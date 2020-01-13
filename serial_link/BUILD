package(default_visibility = ["//visibility:public"])

cc_library(
    name = "serial_link",
    srcs = ["bidir_serial_module.cc"],
    hdrs = ["bidir_serial_module.h"],
    deps = [
        "//module_framework:uc_module",
        "//module_framework:message",
        "//hardware_abstraction:arduino_simulator",
    ],
)

cc_test(
    name = "bidir_serial_module_test",
    srcs = ["bidir_serial_module_test.cc"],
    deps = [
        ":serial_link",
        "@google_googletest//:gtest",
        "@google_googletest//:gtest_main"
    ],
)

cc_binary(
    name = "bidir_serial_main_for_test",
    srcs = ["bidir_serial_main_for_test.cc"],
    deps = [
        ":serial_link",
        "//module_framework:message",
        "//hardware_abstraction:arduino_simulator",
    ],
)
