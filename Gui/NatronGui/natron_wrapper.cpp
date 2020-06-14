
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
#include "natrongui_python.h"

// main header
#include "natron_wrapper.h"

// inner classes
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
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.printAsRAM");
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
    "1:NatronGui.Natron",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_slots
};

} //extern "C"


// Type conversion functions.

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *NatronGuiNatron_SignatureStrings[] = {
    "NatronGui.Natron.getAmountFreePhysicalRAM()->std.size_t",
    "NatronGui.Natron.getSystemTotalRAM()->unsigned long long",
    "NatronGui.Natron.getSystemTotalRAM_conditionnally()->unsigned long long",
    "NatronGui.Natron.isApplication32Bits()->bool",
    "NatronGui.Natron.printAsRAM(bytes:unsigned long long)->QString",
    nullptr}; // Sentinel

void init_NatronGuiNatron(PyObject *module)
{
    _Sbk_Natron_Type = Shiboken::ObjectType::introduceWrapperType(
        module,
        "Natron",
        "Natron",
        &Sbk_Natron_spec,
        NatronGuiNatron_SignatureStrings,
        0,
        0,
        0,
        0    );
    
    SbkNatronGuiTypes[SBK_NatronGuiNATRON_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_TypeF());



}
