package(default_visibility = ["//visibility:public"])

cc_library(name = "hardware_abstraction",
           # TODO: alternate implementation for arduino mode.
           hdrs = ["arduino.h"],
           deps = [":arduino_simulator"])


cc_library(name = "arduino_simulator",
           srcs = ["arduino_simulator.cc"],
           hdrs = ["arduino_simulator.h"])

cc_test(name = "arduino_simulator_test",
        srcs = ["arduino_simulator_test.cc"],
        deps = [":arduino_simulator",
                "@google_googletest//:gtest",
                "@google_googletest//:gtest_main"
                ])
