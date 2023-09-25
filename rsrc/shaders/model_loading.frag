#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

struct Material {
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
    sampler2D texture_normal1;
    float shininess; // рассеивание/радиус зеркального блика
};

struct DirLight {
    vec3 direction;

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

vec3 calculateDirLight(DirLight light, vec3 norm, vec3 viewDir);
vec3 calculateSpotLight(SpotLight light, vec3 norm, vec3 viewDir);

uniform vec3 viewPos;
uniform Material material;
uniform DirLight dirLight1;
uniform SpotLight spotLight1;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 viewDir = normalize(viewPos - FragPos);

    vec3 outputVec = calculateDirLight(dirLight1, norm, viewDir);

    outputVec += calculateSpotLight(spotLight1, norm, viewDir);

    FragColor = vec4(outputVec, 1.0);
    //    FragColor = texture(material.texture_diffuse1, TexCoords);
}

vec3 calculateDirLight(DirLight light, vec3 norm, vec3 viewDir){
    vec3 lightDir = normalize(-light.direction);

    // рассеянное затенение
    float diff = max(dot(norm, lightDir), 0.0);

    // отраженное затенение затенение
    vec3 reflectDir = reflect(-lightDir, norm);// -lightDir потому что reflect() предполагает, что первый вектор направлен от источника света(у нас наоборот)
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);// значение блеска свечения (чем выше - тем больше отражается свет)

    // комбинируем результаты
    vec3 ambient = light.ambient * texture(material.texture_diffuse1, TexCoords).rgb;
    vec3 diffuse = light.diffuse * diff * texture(material.texture_diffuse1, TexCoords).rgb;
    vec3 specular = light.specular * spec * texture(material.texture_specular1, TexCoords).rgb;

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
    vec3 ambient = light.ambient * texture(material.texture_diffuse1, TexCoords).rgb;
    vec3 diffuse = light.diffuse * diff * texture(material.texture_diffuse1, TexCoords).rgb;
    vec3 specular = light.specular * spec * texture(material.texture_specular1, TexCoords).rrr;

    diffuse  *= intensity;
    specular *= intensity;

    ambient *= attenuation;
    diffuse *= attenuation;
    specular *= attenuation;

    // результат
    return vec3(ambient + diffuse + specular);
}