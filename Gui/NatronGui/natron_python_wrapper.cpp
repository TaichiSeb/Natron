
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
#include "natron_python_wrapper.h"

// inner classes
#include "natron_python_pytabwidget_wrapper.h"
#include "natron_python_pyviewer_wrapper.h"
#include "natron_python_pypanel_wrapper.h"
#include "natron_python_pymodaldialog_wrapper.h"
#include "natron_python_guiapp_wrapper.h"

// Extra includes


#include <cctype>
#include <cstring>
using namespace Natron;



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
static PyObject *Sbk_Natron_PythonFunc_makeNameScriptFriendly(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Python::makeNameScriptFriendly(std::string)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // makeNameScriptFriendly(std::string)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_makeNameScriptFriendly_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // makeNameScriptFriendly(std::string)
            std::string cppResult = ::Natron::Python::makeNameScriptFriendly(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_makeNameScriptFriendly_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.makeNameScriptFriendly");
        return {};
}

static PyObject *Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots(PyObject *self, PyObject *pyArg)
{
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: static Python::makeNameScriptFriendlyWithDots(std::string)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), (pyArg)))) {
        overloadId = 0; // makeNameScriptFriendlyWithDots(std::string)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots_TypeError;

    // Call function/method
    {
        ::std::string cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // makeNameScriptFriendlyWithDots(std::string)
            std::string cppResult = ::Natron::Python::makeNameScriptFriendlyWithDots(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<std::string>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.makeNameScriptFriendlyWithDots");
        return {};
}

static PyMethodDef Sbk_Natron_Python_methods[] = {
    {"makeNameScriptFriendly", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_makeNameScriptFriendly), METH_O|METH_STATIC},
    {"makeNameScriptFriendlyWithDots", reinterpret_cast<PyCFunction>(Sbk_Natron_PythonFunc_makeNameScriptFriendlyWithDots), METH_O|METH_STATIC},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_TypeF(void)
{
    return _Sbk_Natron_Python_Type;
}

static PyType_Slot Sbk_Natron_Python_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(Sbk_object_dealloc /* PYSIDE-832: Prevent replacement of "0" with subtype_dealloc. */)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_spec = {
    "1:NatronGui.Natron.Python",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_slots
};

} //extern "C"


// Type conversion functions.

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *NatronGuiNatron_Python_SignatureStrings[] = {
    "NatronGui.Natron.Python.makeNameScriptFriendly(str:std.string)->std.string",
    "NatronGui.Natron.Python.makeNameScriptFriendlyWithDots(str:std.string)->std.string",
    nullptr}; // Sentinel

void init_NatronGuiNatron_Python(PyObject *enclosingClass)
{
    _Sbk_Natron_Python_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "Python",
        "Natron::Python",
        &Sbk_Natron_Python_spec,
        NatronGuiNatron_Python_SignatureStrings,
        0,
        0,
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    SbkNatronGuiTypes[SBK_NatronGuiNATRON_PYTHON_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_TypeF());



}
