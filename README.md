# FPM

## Troubleshooting
`GLX: Failed to create context: GLXBadFBConfig (65543)`
The OpenGL version you are trying to use does not match the one supported by your devive. Check `glxinfo | grep "OpenGL version"` for the supported version and edit `FPM_OPENGL_MAJOR` and `FPM_OPENGL_MINOR` in `include/fpm/fpm.h`.
