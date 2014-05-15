#version 150

out vec4  fColor;
uniform vec4 fColorIn = { 1.0, 1.0, 1.0, 1.0 };

void
main()
{
    fColor = fColorIn;
}