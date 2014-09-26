//***************************************************************************************
// lighting.fx by Super Rob (C) 2014 No Rights Reserved.
//
// Transforms and colors geometry.
//***************************************************************************************

#include "lightingHelper.fx"

SamplerState mySampler
{
	Filter = MIN_MAG_MIP_POINT;
	AddressU = WRAP;
	AddressV = WRAP;

	BorderColor = float4(0.0f, 0.0f, 0.0f, 1.0f);
};

Texture2D gDiffuseMap;

cbuffer cbPerObject
{
	float4x4 gWVP;
	float4x4 gW;
	float4x4 gInvTransposeW;
	float4x4 gTexTransform;
	float4 gAmbientLight;
};

cbuffer cbPerFrame
{
	PointLight gPointLight;
	float3 gEyePos;
	//DirectionalLight dirLight;
	SpotLight gSpotLight;
};



struct VertexIn
{
	float3 PosL  : POSITION;
	float3 NormalL  : NORMAL;
    float2 Tex : TEXCOORD;
};

struct VertexOut
{
	float4 PosH  : SV_POSITION;
    float2 Tex : TEXCOORD;
	float3 PosW : POSITION;
	float3 NormalW : NORMAL;
};

VertexOut VS(VertexIn vin)
{
	VertexOut vout;
	
	vout.NormalW = mul(vin.NormalL, (float3x3)gInvTransposeW);

	vout.PosW = (float3)mul(float4(vin.PosL, 1.0f), gW);

	// Transform to homogeneous clip space.
	vout.PosH = mul(float4(vin.PosL, 1.0f), gWVP);
	
	// Just pass vertex color into the pixel shader.
	vout.Tex = vin.Tex;// (float2)mul(float4(vin.Tex, 0.0f, 1.0f), gTexTransform);
    
    return vout;
}

float4 PS(VertexOut pin) : SV_Target
{
	Material mat;
	mat.diffuse = gDiffuseMap.Sample(mySampler, pin.Tex);
	return mat.diffuse;
	mat.specular = float4(0.75f, 0.75f, 0.75f, 1000.0f);

	float3 toEye = normalize(gEyePos - pin.PosW);

	float4 d, s;

	ComputePointLightToon(mat, gPointLight, pin.PosW, pin.NormalW, 
					 toEye, d, s);

	float4 diffuse = d;
	float4 specular = s;

	ComputeSpotLightToon(mat, gSpotLight, pin.PosW, pin.NormalW, toEye, d, s);

	diffuse += d;
	specular += s;

	float4 litColour = gAmbientLight * mat.diffuse + diffuse + specular;
	litColour.a = mat.diffuse.a;

	return litColour;
}

technique11 TestTech
{
    pass P0
    {
        SetVertexShader( CompileShader( vs_5_0, VS() ) );
		SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_5_0, PS() ) );
    }
}
