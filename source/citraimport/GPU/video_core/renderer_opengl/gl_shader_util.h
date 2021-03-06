// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <citraimport/glad/include/glad/glad.h>

namespace ShaderUtil {

GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path);

}
