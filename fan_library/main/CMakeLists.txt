idf_component_register(SRCS "Fan.c" "main.c"
                    INCLUDE_DIRS ".")
target_include_directories(${COMPONENT_LIB} PUBLIC ".")
