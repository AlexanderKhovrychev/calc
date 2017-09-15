CONFIG += c++14

INCLUDEPATH += ../../googletest/googletest/include/
INCLUDEPATH += ../../googletest/googletest/
INCLUDEPATH += ../

SOURCES += \
    main.cpp \
    ../../googletest/googletest/src/gtest.cc \
    ../../googletest/googletest/src/gtest-all.cc \
    ../../googletest/googletest/src/gtest-death-test.cc \
    ../../googletest/googletest/src/gtest-filepath.cc \
    ../../googletest/googletest/src/gtest-port.cc \
    ../../googletest/googletest/src/gtest-printers.cc \
    ../../googletest/googletest/src/gtest-test-part.cc \
    ../../googletest/googletest/src/gtest-typed-test.cc \
    ../calculator.cpp

HEADERS += \
    ../../googletest/googletest/include/gtest/gtest.h \
    ../../googletest/googletest/include/gtest/gtest_pred_impl.h \
    ../../googletest/googletest/include/gtest/gtest_prod.h \
    ../../googletest/googletest/include/gtest/gtest-death-test.h \
    ../../googletest/googletest/include/gtest/gtest-message.h \
    ../../googletest/googletest/include/gtest/gtest-param-test.h \
    ../../googletest/googletest/include/gtest/gtest-printers.h \
    ../../googletest/googletest/include/gtest/gtest-spi.h \
    ../../googletest/googletest/include/gtest/gtest-test-part.h \
    ../../googletest/googletest/include/gtest/gtest-typed-test.h \
    ../../googletest/googletest/src/gtest-internal-inl.h \
    ../calculator.h
