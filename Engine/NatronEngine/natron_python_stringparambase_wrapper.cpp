
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
#include "natron_python_stringparambase_wrapper.h"

// inner classes

// Extra includes
#include <PyParameter.h>


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

// Native ---------------------------------------------------------

void StringParamBaseWrapper::pysideInitQtMetaTypes()
{
}

void StringParamBaseWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

StringParamBaseWrapper::~StringParamBaseWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Natron_Python_StringParamBaseFunc_addAsDependencyOf(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addAsDependencyOf", 3, 3, &(pyArgs[0]), &(pyArgs[1]), &(pyArgs[2])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::addAsDependencyOf(int,Natron::Python::Param*,int)
    if (numArgs == 3
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArgs[1])))
        && (pythonToCpp[2] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[2])))) {
        overloadId = 0; // addAsDependencyOf(int,Natron::Python::Param*,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_addAsDependencyOf_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        if (!Shiboken::Object::isValid(pyArgs[1]))
            return {};
        ::Natron::Python::Param *cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);
        int cppArg2;
        pythonToCpp[2](pyArgs[2], &cppArg2);

        if (!PyErr_Occurred()) {
            // addAsDependencyOf(int,Natron::Python::Param*,int)
            QString cppResult = cppSelf->addAsDependencyOf(cppArg0, cppArg1, cppArg2);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_StringParamBaseFunc_addAsDependencyOf_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.addAsDependencyOf");
        return {};
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_get(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "get", 0, 1, &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::get()const
    // 1: StringParamBase::get(double)const
    if (numArgs == 0) {
        overloadId = 0; // get()const
    } else if (numArgs == 1
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[0])))) {
        overloadId = 1; // get(double)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_get_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // get() const
        {

            if (!PyErr_Occurred()) {
                // get()const
                QString cppResult = const_cast<const ::Natron::Python::StringParamBase *>(cppSelf)->get();
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
        case 1: // get(double frame) const
        {
            double cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // get(double)const
                QString cppResult = const_cast<const ::Natron::Python::StringParamBase *>(cppSelf)->get(cppArg0);
                pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
            }
            break;
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_StringParamBaseFunc_get_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.get");
        return {};
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_getDefaultValue(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getDefaultValue()const
            QString cppResult = const_cast<const ::Natron::Python::StringParamBase *>(cppSelf)->getDefaultValue();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_getValue(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getValue()const
            QString cppResult = const_cast<const ::Natron::Python::StringParamBase *>(cppSelf)->getValue();
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: StringParamBase::getValueAtTime(double)const
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArg)))) {
        overloadId = 0; // getValueAtTime(double)const
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime_TypeError;

    // Call function/method
    {
        double cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // getValueAtTime(double)const
            QString cppResult = const_cast<const ::Natron::Python::StringParamBase *>(cppSelf)->getValueAtTime(cppArg0);
            pyResult = Shiboken::Conversions::copyToPython(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;

    Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.StringParamBase.getValueAtTime");
        return {};
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_restoreDefaultValue(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // restoreDefaultValue()
            cppSelf->restoreDefaultValue();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_set(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "set", 1, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::set(QString)
    // 1: StringParamBase::set(QString,double)
    if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))) {
        if (numArgs == 1) {
            overloadId = 0; // set(QString)
        } else if (numArgs == 2
            && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
            overloadId = 1; // set(QString,double)
        }
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_set_TypeError;

    // Call function/method
    switch (overloadId) {
        case 0: // set(const QString & x)
        {
            ::QString cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);

            if (!PyErr_Occurred()) {
                // set(QString)
                cppSelf->set(cppArg0);
            }
            break;
        }
        case 1: // set(const QString & x, double frame)
        {
            ::QString cppArg0;
            pythonToCpp[0](pyArgs[0], &cppArg0);
            double cppArg1;
            pythonToCpp[1](pyArgs[1], &cppArg1);

            if (!PyErr_Occurred()) {
                // set(QString,double)
                cppSelf->set(cppArg0, cppArg1);
            }
            break;
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_set_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.set");
        return {};
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_setDefaultValue(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: StringParamBase::setDefaultValue(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setDefaultValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_setDefaultValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setDefaultValue(QString)
            cppSelf->setDefaultValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_setDefaultValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.StringParamBase.setDefaultValue");
        return {};
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_setValue(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: StringParamBase::setValue(QString)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArg)))) {
        overloadId = 0; // setValue(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_setValue_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setValue(QString)
            cppSelf->setValue(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_setValue_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.StringParamBase.setValue");
        return {};
}

static PyObject *Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setValueAtTime", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: StringParamBase::setValueAtTime(QString,double)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(SbkPySide2_QtCoreTypeConverters[SBK_QSTRING_IDX], (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<double>(), (pyArgs[1])))) {
        overloadId = 0; // setValueAtTime(QString,double)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime_TypeError;

    // Call function/method
    {
        ::QString cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        double cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setValueAtTime(QString,double)
            cppSelf->setValueAtTime(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronEngine.Natron.Python.StringParamBase.setValueAtTime");
        return {};
}

static PyMethodDef Sbk_Natron_Python_StringParamBase_methods[] = {
    {"addAsDependencyOf", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_addAsDependencyOf), METH_VARARGS},
    {"get", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_get), METH_VARARGS},
    {"getDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_getDefaultValue), METH_NOARGS},
    {"getValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_getValue), METH_NOARGS},
    {"getValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_getValueAtTime), METH_O},
    {"restoreDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_restoreDefaultValue), METH_NOARGS},
    {"set", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_set), METH_VARARGS},
    {"setDefaultValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_setDefaultValue), METH_O},
    {"setValue", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_setValue), METH_O},
    {"setValueAtTime", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_StringParamBaseFunc_setValueAtTime), METH_VARARGS},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Natron_Python_StringParamBase_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Natron::Python::StringParamBase *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<StringParamBaseWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Natron_Python_StringParamBase_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_StringParamBase_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_StringParamBase_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_StringParamBase_TypeF(void)
{
    return _Sbk_Natron_Python_StringParamBase_Type;
}

static PyType_Slot Sbk_Natron_Python_StringParamBase_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Natron_Python_StringParamBase_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_StringParamBase_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_StringParamBase_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_StringParamBase_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_StringParamBase_spec = {
    "1:NatronEngine.Natron.Python.StringParamBase",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_StringParamBase_slots
};

} //extern "C"

static void *Sbk_Natron_Python_StringParamBase_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::StringParamBase *>(reinterpret_cast< ::Natron::Python::Param *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void StringParamBase_PythonToCpp_StringParamBase_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_StringParamBase_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_StringParamBase_PythonToCpp_StringParamBase_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_StringParamBase_TypeF())))
        return StringParamBase_PythonToCpp_StringParamBase_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *StringParamBase_PTR_CppToPython_StringParamBase(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::StringParamBase *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_StringParamBase_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_StringParamBase_SignatureStrings[] = {
    "NatronEngine.Natron.Python.StringParamBase.addAsDependencyOf(fromExprDimension:int,param:NatronEngine.Natron.Python.Param,thisDimension:int)->QString",
    "1:NatronEngine.Natron.Python.StringParamBase.get()->QString",
    "0:NatronEngine.Natron.Python.StringParamBase.get(frame:double)->QString",
    "NatronEngine.Natron.Python.StringParamBase.getDefaultValue()->QString",
    "NatronEngine.Natron.Python.StringParamBase.getValue()->QString",
    "NatronEngine.Natron.Python.StringParamBase.getValueAtTime(time:double)->QString",
    "NatronEngine.Natron.Python.StringParamBase.restoreDefaultValue()",
    "1:NatronEngine.Natron.Python.StringParamBase.set(x:QString)",
    "0:NatronEngine.Natron.Python.StringParamBase.set(x:QString,frame:double)",
    "NatronEngine.Natron.Python.StringParamBase.setDefaultValue(value:QString)",
    "NatronEngine.Natron.Python.StringParamBase.setValue(value:QString)",
    "NatronEngine.Natron.Python.StringParamBase.setValueAtTime(value:QString,time:double)",
    nullptr}; // Sentinel

void init_Natron_Python_StringParamBase(PyObject *enclosingClass)
{
    _Sbk_Natron_Python_StringParamBase_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "StringParamBase",
        "Natron::Python::StringParamBase*",
        &Sbk_Natron_Python_StringParamBase_spec,
        Natron_Python_StringParamBase_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::StringParamBase >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_ANIMATEDPARAM_IDX]),
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_STRINGPARAMBASE_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_StringParamBase_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_StringParamBase_TypeF(),
        StringParamBase_PythonToCpp_StringParamBase_PTR,
        is_StringParamBase_PythonToCpp_StringParamBase_PTR_Convertible,
        StringParamBase_PTR_CppToPython_StringParamBase);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParamBase");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParamBase*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::StringParamBase&");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParamBase");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParamBase*");
    Shiboken::Conversions::registerConverterName(converter, "Python::StringParamBase&");
    Shiboken::Conversions::registerConverterName(converter, "StringParamBase");
    Shiboken::Conversions::registerConverterName(converter, "StringParamBase*");
    Shiboken::Conversions::registerConverterName(converter, "StringParamBase&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::StringParamBase).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::StringParamBaseWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_StringParamBase_TypeF(), &Sbk_Natron_Python_StringParamBase_typeDiscovery);


    StringParamBaseWrapper::pysideInitQtMetaTypes();
}
