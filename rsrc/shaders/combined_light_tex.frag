#version 330 core

out vec4 FragColor;

struct Material {
    sampler2D diffuse;// цвет поверхности при рассеянном освещении освещении
    sampler2D specular;// цвет зеркального блика на поверхности
    float shininess;// рассеивание/радиус зеркального блика
};

struct DirLight {
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

struct SpotLight {
    vec3 position;
    vec3 direction;

    float cutOff;
    float outerCutOff;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;

uniform DirLight dirLight;
#define NR_OF_POINTS_LIGHT 4
uniform PointLight pointLights[NR_OF_POINTS_LIGHT];
uniform SpotLight spotLight;

uniform Material material;

vec3 calculateDirLight(DirLight light, vec3 norm, vec3 viewDir);
vec3 calculatePointLight(PointLight light, vec3 norm, vec3 viewDir);
vec3 calculateSpotLight(SpotLight light, vec3 norm, vec3 viewDir);

void main() {
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    vec3 outputVec = calculateDirLight(dirLight, norm, viewDir);

    for (int i = 0; i < NR_OF_POINTS_LIGHT; ++i) {
        outputVec += calculatePointLight(pointLights[i], norm, viewDir);
    }

    outputVec += calculateSpotLight(spotLight, norm, viewDir);

    FragColor = vec4(outputVec, 1.0);
}

vec3 calculateDirLight(DirLight light, vec3 norm, vec3 viewDir){
    vec3 lightDir = normalize(-light.direction);

    // рассеянное затенение
    float diff = max(dot(norm, lightDir), 0.0);

    // отраженное затенение затенение
    vec3 reflectDir = reflect(-lightDir, norm);// -lightDir потому что reflect() предполагает, что первый вектор направлен от источника света(у нас наоборот)
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);// значение блеска свечения (чем выше - тем больше отражается свет)

    // комбинируем результаты
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;

    return vec3(ambient + diffuse + specular);
}

vec3 calculatePointLight(PointLight light, vec3 norm, vec3 viewDir) {
    vec3 difference = light.position - FragPos;
    vec3 lightDir = normalize(difference);

    // рассеянное затенение
    float diff = max(dot(norm, lightDir), 0.0);

    // отраженное затенение затенение
    vec3 reflectDir = reflect(-lightDir, norm);// -lightDir потому что reflect() предполагает, что первый вектор направлен от источника света(у нас наоборот)
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);// значение блеска свечения (чем выше - тем больше отражается свет)

    // затухание
    float distance = length(difference);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    // комбинируем результаты
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;
    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    return vec3(ambient + diffuse + specular);
}

vec3 calculateSpotLight(SpotLight light, vec3 norm, vec3 viewDir) {
    vec3 lightDir = normalize(light.position - FragPos);

    // рассеянное затенение
    float diff = max(dot(norm, lightDir), 0.0);

    // отраженное затенение затенение
    vec3 reflectDir = reflect(-lightDir, norm);// -lightDir потому что reflect() предполагает, что первый вектор направлен от источника света(у нас наоборот)
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);// значение блеска свечения (чем выше - тем больше отражается свет)

    // Затухание
    float distance = length(light.position - FragPos);
    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));

    // Прожектор
    float theta = dot(lightDir, normalize(-light.direction));
    float epsilon = (light.cutOff - light.outerCutOff);
    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0);

    // комбинируем результаты
    vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
    vec3 diffuse = light.diffuse * diff * texture(material.diffuse, TexCoords).rgb;
    vec3 specular = light.specular * spec * texture(material.specular, TexCoords).rgb;

    diffuse  *= intensity;
    specular *= intensity;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    // результат
    return vec3(ambient + diffuse + specular);
}