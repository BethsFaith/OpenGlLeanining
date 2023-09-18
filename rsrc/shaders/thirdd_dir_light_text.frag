#version 330 core

out vec4 FragColor;

struct Material {
    sampler2D diffuse;// цвет поверхности при рассеянном освещении освещении
    sampler2D specular;// цвет зеркального блика на поверхности
    float shininess;// рассеивание/радиус зеркального блика
};

struct Light {
    vec3 position;
    vec3 direction;
    int type;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;

    float cutOff;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;
uniform Light light;
uniform Material material;

void main() {
    float attenuation = 1.0f;
    vec3 lightDir;

    if (light.type == 0) { // направленный свет
        lightDir = normalize(-light.position);
    } else if (light.type == 1) { // по положению в пространстве
        vec3 d = light.position - FragPos;
        lightDir = normalize(d);

        float distance = length(d);
        attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
    }

    // фоновое освещение
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;

    // рассеянное освещение
    vec3 norm = normalize(Normal);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;

    // интенсивность отражения
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);// -lightDir потому что reflect() предполагает, что первый вектор направлен от источника света(у нас наоборот)
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);// значение блеска свечения (чем выше - тем больше отражается свет)
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;

    // результат
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    vec3 result = (ambient + diffuse + specular);

    FragColor = vec4(result, 1.0);
}