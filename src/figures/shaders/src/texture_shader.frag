#version 330 core
out vec4 frag_color;

in vec3 our_color;
in vec2 tex_coord;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mix_value;

void main()
{
//    FragColor = vec4(ourColor, 1.0);
//    FragColor = texture(ourTexture, TexCoord);
//    FragColor = texture(texture1, TexCoord) * vec4(ourColor, 1.0);
//    FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
    frag_color = mix(texture(texture1, tex_coord), texture(texture2, vec2(1.0 - tex_coord.x, tex_coord.y)), mix_value);
}