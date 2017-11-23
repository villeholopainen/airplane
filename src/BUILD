

cc_binary(
    name = "twitch",
    srcs = ["twitch.cpp"],
    deps = [
        "@glfw//:glfw",
        #"//src/flappyTwitch:flapper",
        #"//src/engine:engine",
        #"//src/engine/graphics:graphics",
        #"//src/engine/IO:io",
        #"//src/engine/Math:math",
        #"//src/engine/Physics:physics"#,
        #"//3rd_party/glfw:glwf"
    ]
)

filegroup(
    name = "all_source_files",
    data = [
        "//src/flappyTwitch:all_files",
        "//src/engine:all_files",
        "//src/engine/graphics:all_files",
        "//src/engine/IO:all_files",
        "//src/engine/Math:all_files",
        "//src/engine/Physics:all_files",
    ]
)
