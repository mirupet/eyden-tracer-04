#pragma once

#include "ShaderFlat.h"
#include "Scene.h"

/**
* @brief Phong Shader with procedural bump mapping
*/
class CShaderPhongBumpMapped : public CShaderFlat
{
public:
	/**
	 * @brief Constructor
	 * @param scene Reference to the scene
	 * @param color The color of the object
	 * @param ka The ambient coefficient
	 * @param kd The diffuse reflection coefficients
	 * @param ks The specular refelection coefficients
	 * @param ke The shininess exponent
	 */
	CShaderPhongBumpMapped(CScene& scene, Vec3f color, float ka, float kd, float ks, float ke)
		: CShaderFlat(color)
		, m_scene(scene)
		, m_ka(ka)
		, m_kd(kd)
		, m_ks(ks)
		, m_ke(ke)
	{}
	virtual ~CShaderPhongBumpMapped(void) = default;
  
	virtual Vec3f Shade(const Ray& ray) const override
	{
		Vec3f dPdu = (1, 0, 0);
		Vec3f dPdv = (0, 0, 1);
		Vec3f h = ray.org + ray.t * ray.dir;
		float delta_u = 0.5f * cos(3 * h[0] * sin(h[2]));
		float delta_v = 0.5f * sin(13 * h[2]); 

		return RGB(0,0,0);
	}

private:
	CScene& m_scene;
	float 	m_ka;    ///< ambient coefficient
	float 	m_kd;    ///< diffuse reflection coefficients
	float 	m_ks;    ///< specular refelection coefficients
	float 	m_ke;    ///< shininess exponent
};
