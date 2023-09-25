#version 330 core

in vec3 FragPos;
in vec3 Normal;

out vec4 FragColor;

uniform vec3 lightPos;
uniform vec3 viewPos;
uniform vec3 objectColor;
uniform vec3 lightColor;

void main()
{
    // фоновое освещение
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    // рассеянное освещение
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // интенсивность отражения
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm); // -lightDir потому что reflect() предполагает, что первый вектор направлен от источника света(у нас наоборот)

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32); // значение блеска свечения (чем выше - тем больше отражается свет)
    vec3 specular = specularStrength * spec * lightColor;

    // результат
    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
}