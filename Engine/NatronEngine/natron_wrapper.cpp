
// default includes
#include <shiboken.h>
#ifndef QT_NO_VERSION_TAGGING
#  define QT_NO_VERSION_TAGGING
#endif
#include <QDebug>
#include <pysidesignal.h>
#include <pysideproperty.h>
#include <pyside.h>
#include <qapp_macro.h>

QT_WARNING_DISABLE_DEPRECATED

#include <typeinfo>
#include <iterator>

// module include
#include "natronengine_python.h"

// main header
#include "natron_wrapper.h"

// inner classes
#include "natron_recti_wrapper.h"
#include "natron_rectd_wrapper.h"
#include "natron_python_wrapper.h"

// Extra includes
#include <RectD.h>
#include <RectI.h>


#include <cctype>
#include <cstring>



template <class T>
static const char *typeNameOf(const T &t)
{
    const char *typeName =  typeid(t).name();
    auto size = std::strlen(typeName);
#if defined(Q_CC_MSVC) // MSVC: "class QPaintDevice * __ptr64"
    if (auto lastStar = strchr(typeName, '*')) {
        // MSVC: "class QPaintDevice * __ptr64"
        while (*--lastStar == ' ') {
        }
        size = lastStar - typeName + 1;
    }
#else // g++, Clang: "QPaintDevice *" -> "P12QPaintDevice"
    if (size > 2 && typeName[0] == 'P' && std::isdigit(typeName[1])) {
        ++typeName;
        --size;
    }
#endif
    char *result = new char[size + 1];
    result[size] = '\0';
    memcpy(result, typeName, size);
    return result;
}


// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_NatronFunc_getAmountFreePhysicalRAM(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAmountFreePhysicalRAM()
            std::size_t cppResult = ::Natron::getAmountFreePhysicalRAM();
            pyResult = Shiboken::Conversions::copyToPython(SbkNatronEngineTypeConverters[SBK_STD_SIZE_T_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_NatronFunc_getSystemTotalRAM(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getSystemTotalRAM()
            unsigned long long cppResult = ::Natron::getSystemTotalRAM();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long long>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_NatronFunc_getSystemTotalRAM_conditionnally(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getSystemTotalRAM_conditionnally()
            unsigned long long cppResult = ::Natron::getSystemTotalRAM_conditionnally();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long long>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_NatronFunc_isApplication32Bits(PyObject *self)
{
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isApplication32Bits()
            bool cppResult = ::Natron::isApplication32Bits();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_NatronFunc_printAsRAM(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Natron::printAsRAM(unsigned long long)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<unsigned long long>(), (pyArg)))) {
        overloadId = 0; // printAsRAM(unsigned long long)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_NatronFunc_printAsRAM_TypeError;

    // Call function/method
    {
        unsigned long long cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // printAsRAM(unsigned long long)
            QString cppResult = ::Natron::printAsRAM(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_NatronFunc_printAsRAM_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.printAsRAM");
        return {};
}

static PyMethodDef Sbk_Natron_methods[] = {
    {"getAmountFreePhysicalRAM", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_getAmountFreePhysicalRAM), METH_NOARGS|METH_STATIC},
    {"getSystemTotalRAM", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_getSystemTotalRAM), METH_NOARGS|METH_STATIC},
    {"getSystemTotalRAM_conditionnally", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_getSystemTotalRAM_conditionnally), METH_NOARGS|METH_STATIC},
    {"isApplication32Bits", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_isApplication32Bits), METH_NOARGS|METH_STATIC},
    {"printAsRAM", reinterpret_cast<PyCFunction>(Sbk_NatronFunc_printAsRAM), METH_O|METH_STATIC},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Type = nullptr;
static SbkObjectType *Sbk_Natron_TypeF(void)
{
    return _Sbk_Natron_Type;
}

static PyType_Slot Sbk_Natron_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(Sbk_object_dealloc /* PYSIDE-832: Prevent replacement of "0" with subtype_dealloc. */)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_spec = {
    "1:NatronEngine.Natron",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_slots
};

} //extern "C"

PyObject * SbkNatronEngine_Natron_StandardButtonEnum___and__(PyObject *self, PyObject *pyArg)
{
    ::Natron::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, &cppResult);
}

PyObject * SbkNatronEngine_Natron_StandardButtonEnum___or__(PyObject *self, PyObject *pyArg)
{
    ::Natron::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, &cppResult);
}

PyObject * SbkNatronEngine_Natron_StandardButtonEnum___xor__(PyObject *self, PyObject *pyArg)
{
    ::Natron::StandardButtons cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::StandardButtons>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::StandardButtons>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, &cppResult);
}

PyObject *SbkNatronEngine_Natron_StandardButtonEnum___invert__(PyObject *self, PyObject *pyArg)
{
    ::Natron::StandardButtons cppSelf;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, self, &cppSelf);
    ::Natron::StandardButtons cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, &cppResult);
}

static PyObject *SbkNatronEngine_Natron_StandardButtonEnum_long(PyObject *self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkNatronEngine_Natron_StandardButtonEnum__nonzero(PyObject *self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX])->converter, self, &val);
    return val != 0;
}

static PyType_Slot SbkNatronEngine_Natron_StandardButtonEnum_number_slots[] = {
#ifdef IS_PY3K
    {Py_nb_bool,    (void *)SbkNatronEngine_Natron_StandardButtonEnum__nonzero},
#else
    {Py_nb_nonzero, (void *)SbkNatronEngine_Natron_StandardButtonEnum__nonzero},
    {Py_nb_long,    (void *)SbkNatronEngine_Natron_StandardButtonEnum_long},
#endif
    {Py_nb_invert,  (void *)SbkNatronEngine_Natron_StandardButtonEnum___invert__},
    {Py_nb_and,     (void *)SbkNatronEngine_Natron_StandardButtonEnum___and__},
    {Py_nb_xor,     (void *)SbkNatronEngine_Natron_StandardButtonEnum___xor__},
    {Py_nb_or,      (void *)SbkNatronEngine_Natron_StandardButtonEnum___or__},
    {Py_nb_int,     (void *)SbkNatronEngine_Natron_StandardButtonEnum_long},
    {Py_nb_index,   (void *)SbkNatronEngine_Natron_StandardButtonEnum_long},
#ifndef IS_PY3K
    {Py_nb_long,    (void *)SbkNatronEngine_Natron_StandardButtonEnum_long},
#endif
    {0, nullptr} // sentinel
};


PyObject * SbkNatronEngine_Natron_KeyboardModifierEnum___and__(PyObject *self, PyObject *pyArg)
{
    ::Natron::KeyboardModifiers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::KeyboardModifiers>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::KeyboardModifiers>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::KeyboardModifiers>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::KeyboardModifiers>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf & cppArg;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX])->converter, &cppResult);
}

PyObject * SbkNatronEngine_Natron_KeyboardModifierEnum___or__(PyObject *self, PyObject *pyArg)
{
    ::Natron::KeyboardModifiers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::KeyboardModifiers>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::KeyboardModifiers>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::KeyboardModifiers>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::KeyboardModifiers>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf | cppArg;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX])->converter, &cppResult);
}

PyObject * SbkNatronEngine_Natron_KeyboardModifierEnum___xor__(PyObject *self, PyObject *pyArg)
{
    ::Natron::KeyboardModifiers cppResult, cppSelf, cppArg;
#ifdef IS_PY3K
    cppSelf = static_cast<::Natron::KeyboardModifiers>(int(PyLong_AsLong(self)));
    cppArg = static_cast<Natron::KeyboardModifiers>(int(PyLong_AsLong(pyArg)));
#else
    cppSelf = static_cast<::Natron::KeyboardModifiers>(int(PyInt_AsLong(self)));
    cppArg = static_cast<Natron::KeyboardModifiers>(int(PyInt_AsLong(pyArg)));
#endif

    cppResult = cppSelf ^ cppArg;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX])->converter, &cppResult);
}

PyObject *SbkNatronEngine_Natron_KeyboardModifierEnum___invert__(PyObject *self, PyObject *pyArg)
{
    ::Natron::KeyboardModifiers cppSelf;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX])->converter, self, &cppSelf);
    ::Natron::KeyboardModifiers cppResult = ~cppSelf;
    return Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX])->converter, &cppResult);
}

static PyObject *SbkNatronEngine_Natron_KeyboardModifierEnum_long(PyObject *self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX])->converter, self, &val);
    return Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &val);
}
static int SbkNatronEngine_Natron_KeyboardModifierEnum__nonzero(PyObject *self)
{
    int val;
    Shiboken::Conversions::pythonToCppCopy(*PepType_SGTP(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX])->converter, self, &val);
    return val != 0;
}

static PyType_Slot SbkNatronEngine_Natron_KeyboardModifierEnum_number_slots[] = {
#ifdef IS_PY3K
    {Py_nb_bool,    (void *)SbkNatronEngine_Natron_KeyboardModifierEnum__nonzero},
#else
    {Py_nb_nonzero, (void *)SbkNatronEngine_Natron_KeyboardModifierEnum__nonzero},
    {Py_nb_long,    (void *)SbkNatronEngine_Natron_KeyboardModifierEnum_long},
#endif
    {Py_nb_invert,  (void *)SbkNatronEngine_Natron_KeyboardModifierEnum___invert__},
    {Py_nb_and,     (void *)SbkNatronEngine_Natron_KeyboardModifierEnum___and__},
    {Py_nb_xor,     (void *)SbkNatronEngine_Natron_KeyboardModifierEnum___xor__},
    {Py_nb_or,      (void *)SbkNatronEngine_Natron_KeyboardModifierEnum___or__},
    {Py_nb_int,     (void *)SbkNatronEngine_Natron_KeyboardModifierEnum_long},
    {Py_nb_index,   (void *)SbkNatronEngine_Natron_KeyboardModifierEnum_long},
#ifndef IS_PY3K
    {Py_nb_long,    (void *)SbkNatronEngine_Natron_KeyboardModifierEnum_long},
#endif
    {0, nullptr} // sentinel
};



// Type conversion functions.

// Python to C++ enum conversion.
static void Natron_StatusEnum_PythonToCpp_Natron_StatusEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::StatusEnum *>(cppOut) =
        static_cast<::Natron::StatusEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_StatusEnum_PythonToCpp_Natron_StatusEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX]))
        return Natron_StatusEnum_PythonToCpp_Natron_StatusEnum;
    return {};
}
static PyObject *Natron_StatusEnum_CppToPython_Natron_StatusEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::StatusEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX], castCppIn);

}

static void Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::StandardButtonEnum *>(cppOut) =
        static_cast<::Natron::StandardButtonEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]))
        return Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum;
    return {};
}
static PyObject *Natron_StandardButtonEnum_CppToPython_Natron_StandardButtonEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::StandardButtonEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX], castCppIn);

}

static void QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::QFlags<Natron::StandardButtonEnum> *>(cppOut) =
        ::QFlags<Natron::StandardButtonEnum>(QFlag(int(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject *>(pyIn)))));

}
static PythonToCppFunc is_QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX]))
        return QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return {};
}
static PyObject *QFlags_Natron_StandardButtonEnum__CppToPython_QFlags_Natron_StandardButtonEnum_(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::QFlags<Natron::StandardButtonEnum> *>(cppIn));
    return reinterpret_cast<PyObject *>(PySide::QFlags::newObject(castCppIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX]));

}

static void Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::QFlags<Natron::StandardButtonEnum> *>(cppOut) =
        ::QFlags<Natron::StandardButtonEnum>(QFlag(int(Shiboken::Enum::getValue(pyIn))));

}
static PythonToCppFunc is_Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]))
        return Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return {};
}
static void number_PythonToCpp_QFlags_Natron_StandardButtonEnum_(PyObject *pyIn, void *cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *reinterpret_cast<::QFlags<Natron::StandardButtonEnum> *>(cppOut) =
        ::QFlags<Natron::StandardButtonEnum>(QFlag(int(PyLong_AsLong(pyLong.object()))));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible(PyObject *pyIn) {
    if (PyNumber_Check(pyIn) && PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX]))
        return number_PythonToCpp_QFlags_Natron_StandardButtonEnum_;
    return {};
}
static void Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::KeyframeTypeEnum *>(cppOut) =
        static_cast<::Natron::KeyframeTypeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX]))
        return Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum;
    return {};
}
static PyObject *Natron_KeyframeTypeEnum_CppToPython_Natron_KeyframeTypeEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::KeyframeTypeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX], castCppIn);

}

static void Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::PixmapEnum *>(cppOut) =
        static_cast<::Natron::PixmapEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX]))
        return Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum;
    return {};
}
static PyObject *Natron_PixmapEnum_CppToPython_Natron_PixmapEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::PixmapEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX], castCppIn);

}

static void Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ValueChangedReasonEnum *>(cppOut) =
        static_cast<::Natron::ValueChangedReasonEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX]))
        return Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum;
    return {};
}
static PyObject *Natron_ValueChangedReasonEnum_CppToPython_Natron_ValueChangedReasonEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ValueChangedReasonEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX], castCppIn);

}

static void Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::AnimationLevelEnum *>(cppOut) =
        static_cast<::Natron::AnimationLevelEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX]))
        return Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum;
    return {};
}
static PyObject *Natron_AnimationLevelEnum_CppToPython_Natron_AnimationLevelEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::AnimationLevelEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX], castCppIn);

}

static void Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ImagePremultiplicationEnum *>(cppOut) =
        static_cast<::Natron::ImagePremultiplicationEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX]))
        return Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum;
    return {};
}
static PyObject *Natron_ImagePremultiplicationEnum_CppToPython_Natron_ImagePremultiplicationEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ImagePremultiplicationEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX], castCppIn);

}

static void Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ViewerCompositingOperatorEnum *>(cppOut) =
        static_cast<::Natron::ViewerCompositingOperatorEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX]))
        return Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum;
    return {};
}
static PyObject *Natron_ViewerCompositingOperatorEnum_CppToPython_Natron_ViewerCompositingOperatorEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ViewerCompositingOperatorEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX], castCppIn);

}

static void Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ViewerColorSpaceEnum *>(cppOut) =
        static_cast<::Natron::ViewerColorSpaceEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX]))
        return Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum;
    return {};
}
static PyObject *Natron_ViewerColorSpaceEnum_CppToPython_Natron_ViewerColorSpaceEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ViewerColorSpaceEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX], castCppIn);

}

static void Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::ImageBitDepthEnum *>(cppOut) =
        static_cast<::Natron::ImageBitDepthEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX]))
        return Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum;
    return {};
}
static PyObject *Natron_ImageBitDepthEnum_CppToPython_Natron_ImageBitDepthEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::ImageBitDepthEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX], castCppIn);

}

static void Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::OrientationEnum *>(cppOut) =
        static_cast<::Natron::OrientationEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX]))
        return Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum;
    return {};
}
static PyObject *Natron_OrientationEnum_CppToPython_Natron_OrientationEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::OrientationEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX], castCppIn);

}

static void Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::PlaybackModeEnum *>(cppOut) =
        static_cast<::Natron::PlaybackModeEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX]))
        return Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum;
    return {};
}
static PyObject *Natron_PlaybackModeEnum_CppToPython_Natron_PlaybackModeEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::PlaybackModeEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX], castCppIn);

}

static void Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::DisplayChannelsEnum *>(cppOut) =
        static_cast<::Natron::DisplayChannelsEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX]))
        return Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum;
    return {};
}
static PyObject *Natron_DisplayChannelsEnum_CppToPython_Natron_DisplayChannelsEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::DisplayChannelsEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX], castCppIn);

}

static void Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::MergingFunctionEnum *>(cppOut) =
        static_cast<::Natron::MergingFunctionEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX]))
        return Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum;
    return {};
}
static PyObject *Natron_MergingFunctionEnum_CppToPython_Natron_MergingFunctionEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::MergingFunctionEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX], castCppIn);

}

static void Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::KeyboardModifierEnum *>(cppOut) =
        static_cast<::Natron::KeyboardModifierEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX]))
        return Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum;
    return {};
}
static PyObject *Natron_KeyboardModifierEnum_CppToPython_Natron_KeyboardModifierEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::KeyboardModifierEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX], castCppIn);

}

static void QFlags_Natron_KeyboardModifierEnum__PythonToCpp_QFlags_Natron_KeyboardModifierEnum_(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::QFlags<Natron::KeyboardModifierEnum> *>(cppOut) =
        ::QFlags<Natron::KeyboardModifierEnum>(QFlag(int(PySide::QFlags::getValue(reinterpret_cast<PySideQFlagsObject *>(pyIn)))));

}
static PythonToCppFunc is_QFlags_Natron_KeyboardModifierEnum__PythonToCpp_QFlags_Natron_KeyboardModifierEnum__Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX]))
        return QFlags_Natron_KeyboardModifierEnum__PythonToCpp_QFlags_Natron_KeyboardModifierEnum_;
    return {};
}
static PyObject *QFlags_Natron_KeyboardModifierEnum__CppToPython_QFlags_Natron_KeyboardModifierEnum_(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::QFlags<Natron::KeyboardModifierEnum> *>(cppIn));
    return reinterpret_cast<PyObject *>(PySide::QFlags::newObject(castCppIn, SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX]));

}

static void Natron_KeyboardModifierEnum_PythonToCpp_QFlags_Natron_KeyboardModifierEnum_(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::QFlags<Natron::KeyboardModifierEnum> *>(cppOut) =
        ::QFlags<Natron::KeyboardModifierEnum>(QFlag(int(Shiboken::Enum::getValue(pyIn))));

}
static PythonToCppFunc is_Natron_KeyboardModifierEnum_PythonToCpp_QFlags_Natron_KeyboardModifierEnum__Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX]))
        return Natron_KeyboardModifierEnum_PythonToCpp_QFlags_Natron_KeyboardModifierEnum_;
    return {};
}
static void number_PythonToCpp_QFlags_Natron_KeyboardModifierEnum_(PyObject *pyIn, void *cppOut) {
    Shiboken::AutoDecRef pyLong(PyNumber_Long(pyIn));
    *reinterpret_cast<::QFlags<Natron::KeyboardModifierEnum> *>(cppOut) =
        ::QFlags<Natron::KeyboardModifierEnum>(QFlag(int(PyLong_AsLong(pyLong.object()))));

}
static PythonToCppFunc is_number_PythonToCpp_QFlags_Natron_KeyboardModifierEnum__Convertible(PyObject *pyIn) {
    if (PyNumber_Check(pyIn) && PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX]))
        return number_PythonToCpp_QFlags_Natron_KeyboardModifierEnum_;
    return {};
}
static void Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum(PyObject *pyIn, void *cppOut) {
    *reinterpret_cast<::Natron::AppInstanceStatusEnum *>(cppOut) =
        static_cast<::Natron::AppInstanceStatusEnum>(Shiboken::Enum::getValue(pyIn));

}
static PythonToCppFunc is_Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum_Convertible(PyObject *pyIn) {
    if (PyObject_TypeCheck(pyIn, SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX]))
        return Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum;
    return {};
}
static PyObject *Natron_AppInstanceStatusEnum_CppToPython_Natron_AppInstanceStatusEnum(const void *cppIn) {
    const int castCppIn = int(*reinterpret_cast<const ::Natron::AppInstanceStatusEnum *>(cppIn));
    return Shiboken::Enum::newItem(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX], castCppIn);

}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *NatronEngineNatron_SignatureStrings[] = {
    "NatronEngine.Natron.getAmountFreePhysicalRAM()->std.size_t",
    "NatronEngine.Natron.getSystemTotalRAM()->unsigned long long",
    "NatronEngine.Natron.getSystemTotalRAM_conditionnally()->unsigned long long",
    "NatronEngine.Natron.isApplication32Bits()->bool",
    "NatronEngine.Natron.printAsRAM(bytes:unsigned long long)->QString",
    nullptr}; // Sentinel

void init_NatronEngineNatron(PyObject *module)
{
    _Sbk_Natron_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Natron",
        "Natron",
        &Sbk_Natron_spec,
        NatronEngineNatron_SignatureStrings,
        0,
        0,
        0,
        0    );
    
    SbkNatronEngineTypes[SBK_NatronEngineNATRON_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_TypeF());


    // Initialization of enums.

    // Initialization of enum 'StatusEnum'.
    SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "StatusEnum",
        "1:NatronEngine.Natron.StatusEnum",
        "Natron::StatusEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusOK", (long) Natron::StatusEnum::eStatusOK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusFailed", (long) Natron::StatusEnum::eStatusFailed))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusOutOfMemory", (long) Natron::StatusEnum::eStatusOutOfMemory))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eStatusReplyDefault", (long) Natron::StatusEnum::eStatusReplyDefault))
        return;
    // Register converter for enum 'Natron::StatusEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX],
            Natron_StatusEnum_CppToPython_Natron_StatusEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StatusEnum_PythonToCpp_Natron_StatusEnum,
            is_Natron_StatusEnum_PythonToCpp_Natron_StatusEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STATUSENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StatusEnum");
        Shiboken::Conversions::registerConverterName(converter, "StatusEnum");
    }
    // End of 'StatusEnum' enum.

    // Initialization of enum 'StandardButtonEnum'.
    SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX] = PySide::QFlags::create("1:NatronEngine.Natron.StandardButtons", SbkNatronEngine_Natron_StandardButtonEnum_number_slots);
    SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "StandardButtonEnum",
        "1:NatronEngine.Natron.StandardButtonEnum",
        "Natron::StandardButtonEnum",
        SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX]);
    if (!SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonNoButton", (long) Natron::StandardButtonEnum::eStandardButtonNoButton))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonEscape", (long) Natron::StandardButtonEnum::eStandardButtonEscape))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonOk", (long) Natron::StandardButtonEnum::eStandardButtonOk))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonSave", (long) Natron::StandardButtonEnum::eStandardButtonSave))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonSaveAll", (long) Natron::StandardButtonEnum::eStandardButtonSaveAll))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonOpen", (long) Natron::StandardButtonEnum::eStandardButtonOpen))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonYes", (long) Natron::StandardButtonEnum::eStandardButtonYes))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonYesToAll", (long) Natron::StandardButtonEnum::eStandardButtonYesToAll))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonNo", (long) Natron::StandardButtonEnum::eStandardButtonNo))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonNoToAll", (long) Natron::StandardButtonEnum::eStandardButtonNoToAll))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonAbort", (long) Natron::StandardButtonEnum::eStandardButtonAbort))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonRetry", (long) Natron::StandardButtonEnum::eStandardButtonRetry))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonIgnore", (long) Natron::StandardButtonEnum::eStandardButtonIgnore))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonClose", (long) Natron::StandardButtonEnum::eStandardButtonClose))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonCancel", (long) Natron::StandardButtonEnum::eStandardButtonCancel))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonDiscard", (long) Natron::StandardButtonEnum::eStandardButtonDiscard))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonHelp", (long) Natron::StandardButtonEnum::eStandardButtonHelp))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonApply", (long) Natron::StandardButtonEnum::eStandardButtonApply))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonReset", (long) Natron::StandardButtonEnum::eStandardButtonReset))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
        Sbk_Natron_TypeF(), "eStandardButtonRestoreDefaults", (long) Natron::StandardButtonEnum::eStandardButtonRestoreDefaults))
        return;
    // Register converter for enum 'Natron::StandardButtonEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX],
            Natron_StandardButtonEnum_CppToPython_Natron_StandardButtonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum,
            is_Natron_StandardButtonEnum_PythonToCpp_Natron_StandardButtonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_STANDARDBUTTONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StandardButtonEnum");
        Shiboken::Conversions::registerConverterName(converter, "StandardButtonEnum");
    }
    // Register converter for flag 'QFlags<Natron::StandardButtonEnum>'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX],
            QFlags_Natron_StandardButtonEnum__CppToPython_QFlags_Natron_StandardButtonEnum_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum_,
            is_Natron_StandardButtonEnum_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum_,
            is_QFlags_Natron_StandardButtonEnum__PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Natron_StandardButtonEnum_,
            is_number_PythonToCpp_QFlags_Natron_StandardButtonEnum__Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_STANDARDBUTTONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::StandardButtons");
        Shiboken::Conversions::registerConverterName(converter, "StandardButtons");
    }
    // End of 'StandardButtonEnum' enum/flags.

    // Initialization of enum 'KeyframeTypeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "KeyframeTypeEnum",
        "1:NatronEngine.Natron.KeyframeTypeEnum",
        "Natron::KeyframeTypeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeConstant", (long) Natron::KeyframeTypeEnum::eKeyframeTypeConstant))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeLinear", (long) Natron::KeyframeTypeEnum::eKeyframeTypeLinear))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeSmooth", (long) Natron::KeyframeTypeEnum::eKeyframeTypeSmooth))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeCatmullRom", (long) Natron::KeyframeTypeEnum::eKeyframeTypeCatmullRom))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeCubic", (long) Natron::KeyframeTypeEnum::eKeyframeTypeCubic))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeHorizontal", (long) Natron::KeyframeTypeEnum::eKeyframeTypeHorizontal))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeFree", (long) Natron::KeyframeTypeEnum::eKeyframeTypeFree))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeBroken", (long) Natron::KeyframeTypeEnum::eKeyframeTypeBroken))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyframeTypeNone", (long) Natron::KeyframeTypeEnum::eKeyframeTypeNone))
        return;
    // Register converter for enum 'Natron::KeyframeTypeEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX],
            Natron_KeyframeTypeEnum_CppToPython_Natron_KeyframeTypeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum,
            is_Natron_KeyframeTypeEnum_PythonToCpp_Natron_KeyframeTypeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_KEYFRAMETYPEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::KeyframeTypeEnum");
        Shiboken::Conversions::registerConverterName(converter, "KeyframeTypeEnum");
    }
    // End of 'KeyframeTypeEnum' enum.

    // Initialization of enum 'PixmapEnum'.
    SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "PixmapEnum",
        "1:NatronEngine.Natron.PixmapEnum",
        "Natron::PixmapEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PREVIOUS", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PREVIOUS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_FIRST_FRAME", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_FIRST_FRAME))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_NEXT", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_NEXT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_LAST_FRAME", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_LAST_FRAME))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_NEXT_INCR", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_NEXT_INCR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_NEXT_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_NEXT_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PREVIOUS_INCR", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PREVIOUS_INCR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PREVIOUS_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PREVIOUS_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_REWIND_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_REWIND_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_REWIND_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_REWIND_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PLAY_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PLAY_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PLAY_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PLAY_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_STOP_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_STOP_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_STOP_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_STOP_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PAUSE_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PAUSE_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PAUSE_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PAUSE_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_LOOP_MODE", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_LOOP_MODE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_BOUNCE", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_BOUNCE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_PLAY_ONCE", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_PLAY_ONCE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_TIMELINE_IN", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_TIMELINE_IN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PLAYER_TIMELINE_OUT", (long) Natron::PixmapEnum::NATRON_PIXMAP_PLAYER_TIMELINE_OUT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MAXIMIZE_WIDGET", (long) Natron::PixmapEnum::NATRON_PIXMAP_MAXIMIZE_WIDGET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MINIMIZE_WIDGET", (long) Natron::PixmapEnum::NATRON_PIXMAP_MINIMIZE_WIDGET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLOSE_WIDGET", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLOSE_WIDGET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_HELP_WIDGET", (long) Natron::PixmapEnum::NATRON_PIXMAP_HELP_WIDGET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLOSE_PANEL", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLOSE_PANEL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_HIDE_UNMODIFIED", (long) Natron::PixmapEnum::NATRON_PIXMAP_HIDE_UNMODIFIED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNHIDE_UNMODIFIED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNHIDE_UNMODIFIED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_GROUPBOX_FOLDED", (long) Natron::PixmapEnum::NATRON_PIXMAP_GROUPBOX_FOLDED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_GROUPBOX_UNFOLDED", (long) Natron::PixmapEnum::NATRON_PIXMAP_GROUPBOX_UNFOLDED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNDO", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNDO))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REDO", (long) Natron::PixmapEnum::NATRON_PIXMAP_REDO))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNDO_GRAYSCALE", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNDO_GRAYSCALE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REDO_GRAYSCALE", (long) Natron::PixmapEnum::NATRON_PIXMAP_REDO_GRAYSCALE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RESTORE_DEFAULTS_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_RESTORE_DEFAULTS_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RESTORE_DEFAULTS_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_RESTORE_DEFAULTS_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON", (long) Natron::PixmapEnum::NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON_ANCHOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_TAB_WIDGET_LAYOUT_BUTTON_ANCHOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TAB_WIDGET_SPLIT_HORIZONTALLY", (long) Natron::PixmapEnum::NATRON_PIXMAP_TAB_WIDGET_SPLIT_HORIZONTALLY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TAB_WIDGET_SPLIT_VERTICALLY", (long) Natron::PixmapEnum::NATRON_PIXMAP_TAB_WIDGET_SPLIT_VERTICALLY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CENTER", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CENTER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CLIP_TO_PROJECT_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_FULL_FRAME_ON", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_FULL_FRAME_ON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_FULL_FRAME_OFF", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_FULL_FRAME_OFF))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_REFRESH", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_REFRESH))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_REFRESH_ACTIVE", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_REFRESH_ACTIVE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ROI_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ROI_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ROI_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ROI_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_RENDER_SCALE", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_RENDER_SCALE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_RENDER_SCALE_CHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_RENDER_SCALE_CHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_AUTOCONTRAST_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_AUTOCONTRAST_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_AUTOCONTRAST_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_AUTOCONTRAST_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OPEN_FILE", (long) Natron::PixmapEnum::NATRON_PIXMAP_OPEN_FILE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COLORWHEEL", (long) Natron::PixmapEnum::NATRON_PIXMAP_COLORWHEEL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OVERLAY", (long) Natron::PixmapEnum::NATRON_PIXMAP_OVERLAY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTO_MERGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTO_MERGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COLOR_PICKER", (long) Natron::PixmapEnum::NATRON_PIXMAP_COLOR_PICKER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_IO_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_IO_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_3D_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_3D_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CHANNEL_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_CHANNEL_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COLOR_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_COLOR_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRANSFORM_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRANSFORM_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_DEEP_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_DEEP_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FILTER_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_FILTER_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MULTIVIEW_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_MULTIVIEW_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TOOLSETS_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_TOOLSETS_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MISC_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_MISC_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OPEN_EFFECTS_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_OPEN_EFFECTS_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TIME_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_TIME_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PAINT_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_PAINT_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_KEYER_GROUPING", (long) Natron::PixmapEnum::NATRON_PIXMAP_KEYER_GROUPING))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OTHER_PLUGINS", (long) Natron::PixmapEnum::NATRON_PIXMAP_OTHER_PLUGINS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_READ_IMAGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_READ_IMAGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_WRITE_IMAGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_WRITE_IMAGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COMBOBOX", (long) Natron::PixmapEnum::NATRON_PIXMAP_COMBOBOX))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_COMBOBOX_PRESSED", (long) Natron::PixmapEnum::NATRON_PIXMAP_COMBOBOX_PRESSED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ADD_KEYFRAME", (long) Natron::PixmapEnum::NATRON_PIXMAP_ADD_KEYFRAME))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REMOVE_KEYFRAME", (long) Natron::PixmapEnum::NATRON_PIXMAP_REMOVE_KEYFRAME))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INVERTED", (long) Natron::PixmapEnum::NATRON_PIXMAP_INVERTED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNINVERTED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNINVERTED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VISIBLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_VISIBLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNVISIBLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNVISIBLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_LOCKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_LOCKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UNLOCKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UNLOCKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_LAYER", (long) Natron::PixmapEnum::NATRON_PIXMAP_LAYER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_BEZIER", (long) Natron::PixmapEnum::NATRON_PIXMAP_BEZIER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PENCIL", (long) Natron::PixmapEnum::NATRON_PIXMAP_PENCIL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CURVE", (long) Natron::PixmapEnum::NATRON_PIXMAP_CURVE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_BEZIER_32", (long) Natron::PixmapEnum::NATRON_PIXMAP_BEZIER_32))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ELLIPSE", (long) Natron::PixmapEnum::NATRON_PIXMAP_ELLIPSE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RECTANGLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_RECTANGLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ADD_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_ADD_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REMOVE_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_REMOVE_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CUSP_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_CUSP_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SMOOTH_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_SMOOTH_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REMOVE_FEATHER", (long) Natron::PixmapEnum::NATRON_PIXMAP_REMOVE_FEATHER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_OPEN_CLOSE_CURVE", (long) Natron::PixmapEnum::NATRON_PIXMAP_OPEN_CLOSE_CURVE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SELECT_ALL", (long) Natron::PixmapEnum::NATRON_PIXMAP_SELECT_ALL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SELECT_POINTS", (long) Natron::PixmapEnum::NATRON_PIXMAP_SELECT_POINTS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SELECT_FEATHER", (long) Natron::PixmapEnum::NATRON_PIXMAP_SELECT_FEATHER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SELECT_CURVES", (long) Natron::PixmapEnum::NATRON_PIXMAP_SELECT_CURVES))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_AUTO_KEYING_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_AUTO_KEYING_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_AUTO_KEYING_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_AUTO_KEYING_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_STICKY_SELECTION_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_STICKY_SELECTION_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_STICKY_SELECTION_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_STICKY_SELECTION_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FEATHER_LINK_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_FEATHER_LINK_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FEATHER_LINK_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_FEATHER_LINK_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FEATHER_VISIBLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_FEATHER_VISIBLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FEATHER_UNVISIBLE", (long) Natron::PixmapEnum::NATRON_PIXMAP_FEATHER_UNVISIBLE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RIPPLE_EDIT_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_RIPPLE_EDIT_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RIPPLE_EDIT_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_RIPPLE_EDIT_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_BLUR", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_BLUR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_BUILDUP_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_BUILDUP_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_BUILDUP_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_BUILDUP_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_BURN", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_BURN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_CLONE", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_CLONE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_DODGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_DODGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_ERASER", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_ERASER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_PRESSURE_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_PRESSURE_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_PRESSURE_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_PRESSURE_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_REVEAL", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_REVEAL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_SHARPEN", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_SHARPEN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_SMEAR", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_SMEAR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTOPAINT_SOLID", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTOPAINT_SOLID))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_BOLD_CHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_BOLD_CHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_BOLD_UNCHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_BOLD_UNCHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ITALIC_CHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ITALIC_CHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ITALIC_UNCHECKED", (long) Natron::PixmapEnum::NATRON_PIXMAP_ITALIC_UNCHECKED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLEAR_ALL_ANIMATION", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLEAR_ALL_ANIMATION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLEAR_BACKWARD_ANIMATION", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLEAR_BACKWARD_ANIMATION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CLEAR_FORWARD_ANIMATION", (long) Natron::PixmapEnum::NATRON_PIXMAP_CLEAR_FORWARD_ANIMATION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UPDATE_VIEWER_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UPDATE_VIEWER_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_UPDATE_VIEWER_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_UPDATE_VIEWER_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ADD_TRACK", (long) Natron::PixmapEnum::NATRON_PIXMAP_ADD_TRACK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ADD_USER_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_ADD_USER_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_REMOVE_USER_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_REMOVE_USER_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SHOW_TRACK_ERROR", (long) Natron::PixmapEnum::NATRON_PIXMAP_SHOW_TRACK_ERROR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_HIDE_TRACK_ERROR", (long) Natron::PixmapEnum::NATRON_PIXMAP_HIDE_TRACK_ERROR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RESET_TRACK_OFFSET", (long) Natron::PixmapEnum::NATRON_PIXMAP_RESET_TRACK_OFFSET))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_ON", (long) Natron::PixmapEnum::NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_ON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_OFF", (long) Natron::PixmapEnum::NATRON_PIXMAP_CREATE_USER_KEY_ON_MOVE_OFF))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_RESET_USER_KEYS", (long) Natron::PixmapEnum::NATRON_PIXMAP_RESET_USER_KEYS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_CENTER_VIEWER_ON_TRACK", (long) Natron::PixmapEnum::NATRON_PIXMAP_CENTER_VIEWER_ON_TRACK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_BACKWARD_ON", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_BACKWARD_ON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_BACKWARD_OFF", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_BACKWARD_OFF))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_FORWARD_ON", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_FORWARD_ON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_FORWARD_OFF", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_FORWARD_OFF))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_PREVIOUS", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_PREVIOUS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_NEXT", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_NEXT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_RANGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_RANGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_ALL_KEYS", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_ALL_KEYS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_TRACK_CURRENT_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_TRACK_CURRENT_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_NEXT_USER_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_NEXT_USER_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_PREV_USER_KEY", (long) Natron::PixmapEnum::NATRON_PIXMAP_PREV_USER_KEY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ENTER_GROUP", (long) Natron::PixmapEnum::NATRON_PIXMAP_ENTER_GROUP))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SETTINGS", (long) Natron::PixmapEnum::NATRON_PIXMAP_SETTINGS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FREEZE_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_FREEZE_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_FREEZE_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_FREEZE_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ICON", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ICON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CHECKERBOARD_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CHECKERBOARD_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_CHECKERBOARD_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_CHECKERBOARD_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ZEBRA_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ZEBRA_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_ZEBRA_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_ZEBRA_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_GAMMA_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_GAMMA_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_GAMMA_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_GAMMA_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_GAIN_ENABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_GAIN_ENABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_VIEWER_GAIN_DISABLED", (long) Natron::PixmapEnum::NATRON_PIXMAP_VIEWER_GAIN_DISABLED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_CLEAR_OUTPUT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_CLEAR_OUTPUT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_EXEC_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_EXEC_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_LOAD_EXEC_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_LOAD_EXEC_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_LOAD_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_LOAD_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_NEXT_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_NEXT_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_ACTIVATED", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_ACTIVATED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_DEACTIVATED", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_OUTPUT_PANE_DEACTIVATED))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_PREVIOUS_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_PREVIOUS_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_SCRIPT_SAVE_SCRIPT", (long) Natron::PixmapEnum::NATRON_PIXMAP_SCRIPT_SAVE_SCRIPT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_ATOP", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_ATOP))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_AVERAGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_AVERAGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_COLOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_COLOR_BURN", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR_BURN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_COLOR_DODGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_COLOR_DODGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_CONJOINT_OVER", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_CONJOINT_OVER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_COPY", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_COPY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_DIFFERENCE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_DIFFERENCE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_DISJOINT_OVER", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_DISJOINT_OVER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_DIVIDE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_DIVIDE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_EXCLUSION", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_EXCLUSION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_FREEZE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_FREEZE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_FROM", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_FROM))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_GEOMETRIC", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_GEOMETRIC))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_GRAIN_EXTRACT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_GRAIN_EXTRACT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_GRAIN_MERGE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_GRAIN_MERGE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_HARD_LIGHT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_HARD_LIGHT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_HUE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_HUE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_HYPOT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_HYPOT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_IN", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_IN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_LUMINOSITY", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_LUMINOSITY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MASK", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MASK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MATTE", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MATTE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MAX", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MAX))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MIN", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MIN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MINUS", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MINUS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_MULTIPLY", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_MULTIPLY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_OUT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_OUT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_OVER", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_OVER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_OVERLAY", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_OVERLAY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_PINLIGHT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_PINLIGHT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_PLUS", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_PLUS))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_REFLECT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_REFLECT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_SATURATION", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_SATURATION))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_SCREEN", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_SCREEN))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_SOFT_LIGHT", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_SOFT_LIGHT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_STENCIL", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_STENCIL))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_UNDER", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_UNDER))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_MERGE_XOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_MERGE_XOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_ROTO_NODE_ICON", (long) Natron::PixmapEnum::NATRON_PIXMAP_ROTO_NODE_ICON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_LINK_CURSOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_LINK_CURSOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_LINK_MULT_CURSOR", (long) Natron::PixmapEnum::NATRON_PIXMAP_LINK_MULT_CURSOR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_APP_ICON", (long) Natron::PixmapEnum::NATRON_PIXMAP_APP_ICON))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_LINEAR", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_LINEAR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CONSTANT", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CONSTANT))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_BREAK", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_BREAK))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE_C", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE_C))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE_H", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE_H))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE_R", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE_R))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
        Sbk_Natron_TypeF(), "NATRON_PIXMAP_INTERP_CURVE_Z", (long) Natron::PixmapEnum::NATRON_PIXMAP_INTERP_CURVE_Z))
        return;
    // Register converter for enum 'Natron::PixmapEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX],
            Natron_PixmapEnum_CppToPython_Natron_PixmapEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum,
            is_Natron_PixmapEnum_PythonToCpp_Natron_PixmapEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PIXMAPENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PixmapEnum");
        Shiboken::Conversions::registerConverterName(converter, "PixmapEnum");
    }
    // End of 'PixmapEnum' enum.

    // Initialization of enum 'ValueChangedReasonEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ValueChangedReasonEnum",
        "1:NatronEngine.Natron.ValueChangedReasonEnum",
        "Natron::ValueChangedReasonEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonUserEdited", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonUserEdited))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonPluginEdited", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonPluginEdited))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonNatronGuiEdited", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonNatronGuiEdited))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonNatronInternalEdited", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonNatronInternalEdited))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonTimeChanged", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonTimeChanged))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonSlaveRefresh", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonSlaveRefresh))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
        Sbk_Natron_TypeF(), "eValueChangedReasonRestoreDefault", (long) Natron::ValueChangedReasonEnum::eValueChangedReasonRestoreDefault))
        return;
    // Register converter for enum 'Natron::ValueChangedReasonEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX],
            Natron_ValueChangedReasonEnum_CppToPython_Natron_ValueChangedReasonEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum,
            is_Natron_ValueChangedReasonEnum_PythonToCpp_Natron_ValueChangedReasonEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VALUECHANGEDREASONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ValueChangedReasonEnum");
        Shiboken::Conversions::registerConverterName(converter, "ValueChangedReasonEnum");
    }
    // End of 'ValueChangedReasonEnum' enum.

    // Initialization of enum 'AnimationLevelEnum'.
    SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "AnimationLevelEnum",
        "1:NatronEngine.Natron.AnimationLevelEnum",
        "Natron::AnimationLevelEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
        Sbk_Natron_TypeF(), "eAnimationLevelNone", (long) Natron::AnimationLevelEnum::eAnimationLevelNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
        Sbk_Natron_TypeF(), "eAnimationLevelInterpolatedValue", (long) Natron::AnimationLevelEnum::eAnimationLevelInterpolatedValue))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
        Sbk_Natron_TypeF(), "eAnimationLevelOnKeyframe", (long) Natron::AnimationLevelEnum::eAnimationLevelOnKeyframe))
        return;
    // Register converter for enum 'Natron::AnimationLevelEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX],
            Natron_AnimationLevelEnum_CppToPython_Natron_AnimationLevelEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum,
            is_Natron_AnimationLevelEnum_PythonToCpp_Natron_AnimationLevelEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ANIMATIONLEVELENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::AnimationLevelEnum");
        Shiboken::Conversions::registerConverterName(converter, "AnimationLevelEnum");
    }
    // End of 'AnimationLevelEnum' enum.

    // Initialization of enum 'ImagePremultiplicationEnum'.
    SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ImagePremultiplicationEnum",
        "1:NatronEngine.Natron.ImagePremultiplicationEnum",
        "Natron::ImagePremultiplicationEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eImagePremultiplicationOpaque", (long) Natron::ImagePremultiplicationEnum::eImagePremultiplicationOpaque))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eImagePremultiplicationPremultiplied", (long) Natron::ImagePremultiplicationEnum::eImagePremultiplicationPremultiplied))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eImagePremultiplicationUnPremultiplied", (long) Natron::ImagePremultiplicationEnum::eImagePremultiplicationUnPremultiplied))
        return;
    // Register converter for enum 'Natron::ImagePremultiplicationEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX],
            Natron_ImagePremultiplicationEnum_CppToPython_Natron_ImagePremultiplicationEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum,
            is_Natron_ImagePremultiplicationEnum_PythonToCpp_Natron_ImagePremultiplicationEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEPREMULTIPLICATIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImagePremultiplicationEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImagePremultiplicationEnum");
    }
    // End of 'ImagePremultiplicationEnum' enum.

    // Initialization of enum 'ViewerCompositingOperatorEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ViewerCompositingOperatorEnum",
        "1:NatronEngine.Natron.ViewerCompositingOperatorEnum",
        "Natron::ViewerCompositingOperatorEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorNone", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorWipeUnder", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorWipeUnder))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorWipeOver", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorWipeOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorWipeMinus", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorWipeMinus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorWipeOnionSkin", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorWipeOnionSkin))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorStackUnder", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorStackUnder))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorStackOver", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorStackOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorStackMinus", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorStackMinus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerCompositingOperatorStackOnionSkin", (long) Natron::ViewerCompositingOperatorEnum::eViewerCompositingOperatorStackOnionSkin))
        return;
    // Register converter for enum 'Natron::ViewerCompositingOperatorEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX],
            Natron_ViewerCompositingOperatorEnum_CppToPython_Natron_ViewerCompositingOperatorEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum,
            is_Natron_ViewerCompositingOperatorEnum_PythonToCpp_Natron_ViewerCompositingOperatorEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ViewerCompositingOperatorEnum");
        Shiboken::Conversions::registerConverterName(converter, "ViewerCompositingOperatorEnum");
    }
    // End of 'ViewerCompositingOperatorEnum' enum.

    // Initialization of enum 'ViewerColorSpaceEnum'.
    SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ViewerColorSpaceEnum",
        "1:NatronEngine.Natron.ViewerColorSpaceEnum",
        "Natron::ViewerColorSpaceEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerColorSpaceSRGB", (long) Natron::ViewerColorSpaceEnum::eViewerColorSpaceSRGB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerColorSpaceLinear", (long) Natron::ViewerColorSpaceEnum::eViewerColorSpaceLinear))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
        Sbk_Natron_TypeF(), "eViewerColorSpaceRec709", (long) Natron::ViewerColorSpaceEnum::eViewerColorSpaceRec709))
        return;
    // Register converter for enum 'Natron::ViewerColorSpaceEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX],
            Natron_ViewerColorSpaceEnum_CppToPython_Natron_ViewerColorSpaceEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum,
            is_Natron_ViewerColorSpaceEnum_PythonToCpp_Natron_ViewerColorSpaceEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOLORSPACEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ViewerColorSpaceEnum");
        Shiboken::Conversions::registerConverterName(converter, "ViewerColorSpaceEnum");
    }
    // End of 'ViewerColorSpaceEnum' enum.

    // Initialization of enum 'ImageBitDepthEnum'.
    SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "ImageBitDepthEnum",
        "1:NatronEngine.Natron.ImageBitDepthEnum",
        "Natron::ImageBitDepthEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthNone", (long) Natron::ImageBitDepthEnum::eImageBitDepthNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthByte", (long) Natron::ImageBitDepthEnum::eImageBitDepthByte))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthShort", (long) Natron::ImageBitDepthEnum::eImageBitDepthShort))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthHalf", (long) Natron::ImageBitDepthEnum::eImageBitDepthHalf))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
        Sbk_Natron_TypeF(), "eImageBitDepthFloat", (long) Natron::ImageBitDepthEnum::eImageBitDepthFloat))
        return;
    // Register converter for enum 'Natron::ImageBitDepthEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX],
            Natron_ImageBitDepthEnum_CppToPython_Natron_ImageBitDepthEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum,
            is_Natron_ImageBitDepthEnum_PythonToCpp_Natron_ImageBitDepthEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_IMAGEBITDEPTHENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::ImageBitDepthEnum");
        Shiboken::Conversions::registerConverterName(converter, "ImageBitDepthEnum");
    }
    // End of 'ImageBitDepthEnum' enum.

    // Initialization of enum 'OrientationEnum'.
    SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "OrientationEnum",
        "1:NatronEngine.Natron.OrientationEnum",
        "Natron::OrientationEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eOrientationHorizontal", (long) Natron::OrientationEnum::eOrientationHorizontal))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
        Sbk_Natron_TypeF(), "eOrientationVertical", (long) Natron::OrientationEnum::eOrientationVertical))
        return;
    // Register converter for enum 'Natron::OrientationEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX],
            Natron_OrientationEnum_CppToPython_Natron_OrientationEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum,
            is_Natron_OrientationEnum_PythonToCpp_Natron_OrientationEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_ORIENTATIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::OrientationEnum");
        Shiboken::Conversions::registerConverterName(converter, "OrientationEnum");
    }
    // End of 'OrientationEnum' enum.

    // Initialization of enum 'PlaybackModeEnum'.
    SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "PlaybackModeEnum",
        "1:NatronEngine.Natron.PlaybackModeEnum",
        "Natron::PlaybackModeEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
        Sbk_Natron_TypeF(), "ePlaybackModeLoop", (long) Natron::PlaybackModeEnum::ePlaybackModeLoop))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
        Sbk_Natron_TypeF(), "ePlaybackModeBounce", (long) Natron::PlaybackModeEnum::ePlaybackModeBounce))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
        Sbk_Natron_TypeF(), "ePlaybackModeOnce", (long) Natron::PlaybackModeEnum::ePlaybackModeOnce))
        return;
    // Register converter for enum 'Natron::PlaybackModeEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX],
            Natron_PlaybackModeEnum_CppToPython_Natron_PlaybackModeEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum,
            is_Natron_PlaybackModeEnum_PythonToCpp_Natron_PlaybackModeEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::PlaybackModeEnum");
        Shiboken::Conversions::registerConverterName(converter, "PlaybackModeEnum");
    }
    // End of 'PlaybackModeEnum' enum.

    // Initialization of enum 'DisplayChannelsEnum'.
    SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "DisplayChannelsEnum",
        "1:NatronEngine.Natron.DisplayChannelsEnum",
        "Natron::DisplayChannelsEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsRGB", (long) Natron::DisplayChannelsEnum::eDisplayChannelsRGB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsR", (long) Natron::DisplayChannelsEnum::eDisplayChannelsR))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsG", (long) Natron::DisplayChannelsEnum::eDisplayChannelsG))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsB", (long) Natron::DisplayChannelsEnum::eDisplayChannelsB))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsA", (long) Natron::DisplayChannelsEnum::eDisplayChannelsA))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsY", (long) Natron::DisplayChannelsEnum::eDisplayChannelsY))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
        Sbk_Natron_TypeF(), "eDisplayChannelsMatte", (long) Natron::DisplayChannelsEnum::eDisplayChannelsMatte))
        return;
    // Register converter for enum 'Natron::DisplayChannelsEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX],
            Natron_DisplayChannelsEnum_CppToPython_Natron_DisplayChannelsEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum,
            is_Natron_DisplayChannelsEnum_PythonToCpp_Natron_DisplayChannelsEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::DisplayChannelsEnum");
        Shiboken::Conversions::registerConverterName(converter, "DisplayChannelsEnum");
    }
    // End of 'DisplayChannelsEnum' enum.

    // Initialization of enum 'MergingFunctionEnum'.
    SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "MergingFunctionEnum",
        "1:NatronEngine.Natron.MergingFunctionEnum",
        "Natron::MergingFunctionEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeATop", (long) Natron::MergingFunctionEnum::eMergeATop))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeAverage", (long) Natron::MergingFunctionEnum::eMergeAverage))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeColor", (long) Natron::MergingFunctionEnum::eMergeColor))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeColorBurn", (long) Natron::MergingFunctionEnum::eMergeColorBurn))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeColorDodge", (long) Natron::MergingFunctionEnum::eMergeColorDodge))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeConjointOver", (long) Natron::MergingFunctionEnum::eMergeConjointOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeCopy", (long) Natron::MergingFunctionEnum::eMergeCopy))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeDifference", (long) Natron::MergingFunctionEnum::eMergeDifference))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeDisjointOver", (long) Natron::MergingFunctionEnum::eMergeDisjointOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeDivide", (long) Natron::MergingFunctionEnum::eMergeDivide))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeExclusion", (long) Natron::MergingFunctionEnum::eMergeExclusion))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeFreeze", (long) Natron::MergingFunctionEnum::eMergeFreeze))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeFrom", (long) Natron::MergingFunctionEnum::eMergeFrom))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeGeometric", (long) Natron::MergingFunctionEnum::eMergeGeometric))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeGrainExtract", (long) Natron::MergingFunctionEnum::eMergeGrainExtract))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeGrainMerge", (long) Natron::MergingFunctionEnum::eMergeGrainMerge))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeHardLight", (long) Natron::MergingFunctionEnum::eMergeHardLight))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeHue", (long) Natron::MergingFunctionEnum::eMergeHue))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeHypot", (long) Natron::MergingFunctionEnum::eMergeHypot))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeIn", (long) Natron::MergingFunctionEnum::eMergeIn))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeLuminosity", (long) Natron::MergingFunctionEnum::eMergeLuminosity))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMask", (long) Natron::MergingFunctionEnum::eMergeMask))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMatte", (long) Natron::MergingFunctionEnum::eMergeMatte))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMax", (long) Natron::MergingFunctionEnum::eMergeMax))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMin", (long) Natron::MergingFunctionEnum::eMergeMin))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMinus", (long) Natron::MergingFunctionEnum::eMergeMinus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeMultiply", (long) Natron::MergingFunctionEnum::eMergeMultiply))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeOut", (long) Natron::MergingFunctionEnum::eMergeOut))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeOver", (long) Natron::MergingFunctionEnum::eMergeOver))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeOverlay", (long) Natron::MergingFunctionEnum::eMergeOverlay))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergePinLight", (long) Natron::MergingFunctionEnum::eMergePinLight))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergePlus", (long) Natron::MergingFunctionEnum::eMergePlus))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeReflect", (long) Natron::MergingFunctionEnum::eMergeReflect))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeSaturation", (long) Natron::MergingFunctionEnum::eMergeSaturation))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeScreen", (long) Natron::MergingFunctionEnum::eMergeScreen))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeSoftLight", (long) Natron::MergingFunctionEnum::eMergeSoftLight))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeStencil", (long) Natron::MergingFunctionEnum::eMergeStencil))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeUnder", (long) Natron::MergingFunctionEnum::eMergeUnder))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
        Sbk_Natron_TypeF(), "eMergeXOR", (long) Natron::MergingFunctionEnum::eMergeXOR))
        return;
    // Register converter for enum 'Natron::MergingFunctionEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX],
            Natron_MergingFunctionEnum_CppToPython_Natron_MergingFunctionEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum,
            is_Natron_MergingFunctionEnum_PythonToCpp_Natron_MergingFunctionEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_MERGINGFUNCTIONENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::MergingFunctionEnum");
        Shiboken::Conversions::registerConverterName(converter, "MergingFunctionEnum");
    }
    // End of 'MergingFunctionEnum' enum.

    // Initialization of enum 'KeyboardModifierEnum'.
    SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX] = PySide::QFlags::create("1:NatronEngine.Natron.KeyboardModifiers", SbkNatronEngine_Natron_KeyboardModifierEnum_number_slots);
    SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "KeyboardModifierEnum",
        "1:NatronEngine.Natron.KeyboardModifierEnum",
        "Natron::KeyboardModifierEnum",
        SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX]);
    if (!SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierNone", (long) Natron::KeyboardModifierEnum::eKeyboardModifierNone))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierShift", (long) Natron::KeyboardModifierEnum::eKeyboardModifierShift))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierControl", (long) Natron::KeyboardModifierEnum::eKeyboardModifierControl))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierAlt", (long) Natron::KeyboardModifierEnum::eKeyboardModifierAlt))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierMeta", (long) Natron::KeyboardModifierEnum::eKeyboardModifierMeta))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierKeypad", (long) Natron::KeyboardModifierEnum::eKeyboardModifierKeypad))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierGroupSwitch", (long) Natron::KeyboardModifierEnum::eKeyboardModifierGroupSwitch))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
        Sbk_Natron_TypeF(), "eKeyboardModifierMask", (long) Natron::KeyboardModifierEnum::eKeyboardModifierMask))
        return;
    // Register converter for enum 'Natron::KeyboardModifierEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX],
            Natron_KeyboardModifierEnum_CppToPython_Natron_KeyboardModifierEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum,
            is_Natron_KeyboardModifierEnum_PythonToCpp_Natron_KeyboardModifierEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_KEYBOARDMODIFIERENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::KeyboardModifierEnum");
        Shiboken::Conversions::registerConverterName(converter, "KeyboardModifierEnum");
    }
    // Register converter for flag 'QFlags<Natron::KeyboardModifierEnum>'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX],
            QFlags_Natron_KeyboardModifierEnum__CppToPython_QFlags_Natron_KeyboardModifierEnum_);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_KeyboardModifierEnum_PythonToCpp_QFlags_Natron_KeyboardModifierEnum_,
            is_Natron_KeyboardModifierEnum_PythonToCpp_QFlags_Natron_KeyboardModifierEnum__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            QFlags_Natron_KeyboardModifierEnum__PythonToCpp_QFlags_Natron_KeyboardModifierEnum_,
            is_QFlags_Natron_KeyboardModifierEnum__PythonToCpp_QFlags_Natron_KeyboardModifierEnum__Convertible);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            number_PythonToCpp_QFlags_Natron_KeyboardModifierEnum_,
            is_number_PythonToCpp_QFlags_Natron_KeyboardModifierEnum__Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_QFLAGS_NATRON_KEYBOARDMODIFIERENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::KeyboardModifiers");
        Shiboken::Conversions::registerConverterName(converter, "KeyboardModifiers");
    }
    // End of 'KeyboardModifierEnum' enum/flags.

    // Initialization of enum 'AppInstanceStatusEnum'.
    SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX] = Shiboken::Enum::createScopedEnum(Sbk_Natron_TypeF(),
        "AppInstanceStatusEnum",
        "1:NatronEngine.Natron.AppInstanceStatusEnum",
        "Natron::AppInstanceStatusEnum");
    if (!SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX])
        return;

    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eAppInstanceStatusInactive", (long) Natron::AppInstanceStatusEnum::eAppInstanceStatusInactive))
        return;
    if (!Shiboken::Enum::createScopedEnumItem(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX],
        Sbk_Natron_TypeF(), "eAppInstanceStatusActive", (long) Natron::AppInstanceStatusEnum::eAppInstanceStatusActive))
        return;
    // Register converter for enum 'Natron::AppInstanceStatusEnum'.
    {
        SbkConverter *converter = Shiboken::Conversions::createConverter(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX],
            Natron_AppInstanceStatusEnum_CppToPython_Natron_AppInstanceStatusEnum);
        Shiboken::Conversions::addPythonToCppValueConversion(converter,
            Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum,
            is_Natron_AppInstanceStatusEnum_PythonToCpp_Natron_AppInstanceStatusEnum_Convertible);
        Shiboken::Enum::setTypeConverter(SbkNatronEngineTypes[SBK_NATRON_APPINSTANCESTATUSENUM_IDX], converter);
        Shiboken::Conversions::registerConverterName(converter, "Natron::AppInstanceStatusEnum");
        Shiboken::Conversions::registerConverterName(converter, "AppInstanceStatusEnum");
    }
    // End of 'AppInstanceStatusEnum' enum.


    qRegisterMetaType< ::Natron::StatusEnum >("Natron::StatusEnum");
    qRegisterMetaType< ::Natron::StandardButtonEnum >("Natron::StandardButtonEnum");
    qRegisterMetaType< ::Natron::StandardButtons >("Natron::StandardButtons");
    qRegisterMetaType< ::Natron::KeyframeTypeEnum >("Natron::KeyframeTypeEnum");
    qRegisterMetaType< ::Natron::PixmapEnum >("Natron::PixmapEnum");
    qRegisterMetaType< ::Natron::ValueChangedReasonEnum >("Natron::ValueChangedReasonEnum");
    qRegisterMetaType< ::Natron::AnimationLevelEnum >("Natron::AnimationLevelEnum");
    qRegisterMetaType< ::Natron::ImagePremultiplicationEnum >("Natron::ImagePremultiplicationEnum");
    qRegisterMetaType< ::Natron::ViewerCompositingOperatorEnum >("Natron::ViewerCompositingOperatorEnum");
    qRegisterMetaType< ::Natron::ViewerColorSpaceEnum >("Natron::ViewerColorSpaceEnum");
    qRegisterMetaType< ::Natron::ImageBitDepthEnum >("Natron::ImageBitDepthEnum");
    qRegisterMetaType< ::Natron::OrientationEnum >("Natron::OrientationEnum");
    qRegisterMetaType< ::Natron::PlaybackModeEnum >("Natron::PlaybackModeEnum");
    qRegisterMetaType< ::Natron::DisplayChannelsEnum >("Natron::DisplayChannelsEnum");
    qRegisterMetaType< ::Natron::MergingFunctionEnum >("Natron::MergingFunctionEnum");
    qRegisterMetaType< ::Natron::KeyboardModifierEnum >("Natron::KeyboardModifierEnum");
    qRegisterMetaType< ::Natron::KeyboardModifiers >("Natron::KeyboardModifiers");
    qRegisterMetaType< ::Natron::AppInstanceStatusEnum >("Natron::AppInstanceStatusEnum");
}
