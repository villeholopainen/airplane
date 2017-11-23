package(default_visibility = ["//visibility:public"])

#cc_library(
#    name = "io",
#    srcs = [
#        "keyboard.cpp",
#        "mouse.cpp"
#    ],
#    hdrs = [
#        "keyboard.h",
#        "mouse.h"
#    ]
#)

filegroup(
    name = "all_files",
    srcs = glob(
        ["**/*"],
        exclude = [
            "**/METADATA",
            "**/OWNERS",
        ],
    )
)
