#version 330 core

out vec4 FragColor;

struct Material {
    sampler2D diffuse;  // цвет поверхности при рассеянном освещении освещении
    sampler2D specular;  // цвет зеркального блика на поверхности
    float shininess; // рассеивание/радиус зеркального блика
};

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;
uniform Light light;
uniform Material material;

void main() {
    // фоновое освещение
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;

    // рассеянное освещение
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;

    // интенсивность отражения
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm); // -lightDir потому что reflect() предполагает, что первый вектор направлен от источника света(у нас наоборот)
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess); // значение блеска свечения (чем выше - тем больше отражается свет)
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;

    // результат
    vec3 result = (ambient + diffuse + specular);
    FragColor = vec4(result, 1.0);
}
