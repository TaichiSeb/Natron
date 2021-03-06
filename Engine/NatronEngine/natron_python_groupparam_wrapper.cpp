
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
#include "natron_python_groupparam_wrapper.h"

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

void GroupParamWrapper::pysideInitQtMetaTypes()
{
}

void GroupParamWrapper::resetPyMethodCache()
{
    std::fill_n(m_PyMethodCache, sizeof(m_PyMethodCache) / sizeof(m_PyMethodCache[0]), false);
}

GroupParamWrapper::~GroupParamWrapper()
{
    SbkObject *wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static PyObject *Sbk_Natron_Python_GroupParamFunc_addParam(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<GroupParamWrapper *>(reinterpret_cast< ::Natron::Python::GroupParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUPPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: GroupParam::addParam(const Natron::Python::Param*)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppPointerConvertible(reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]), (pyArg)))) {
        overloadId = 0; // addParam(const Natron::Python::Param*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GroupParamFunc_addParam_TypeError;

    // Call function/method
    {
        if (!Shiboken::Object::isValid(pyArg))
            return {};
        ::Natron::Python::Param *cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // addParam(const Natron::Python::Param*)
            cppSelf->addParam(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GroupParamFunc_addParam_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.GroupParam.addParam");
        return {};
}

static PyObject *Sbk_Natron_Python_GroupParamFunc_getIsOpened(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<GroupParamWrapper *>(reinterpret_cast< ::Natron::Python::GroupParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUPPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getIsOpened()const
            bool cppResult = const_cast<const ::GroupParamWrapper *>(cppSelf)->getIsOpened();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_GroupParamFunc_setAsTab(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<GroupParamWrapper *>(reinterpret_cast< ::Natron::Python::GroupParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUPPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // setAsTab()
            cppSelf->setAsTab();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject *Sbk_Natron_Python_GroupParamFunc_setOpened(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = static_cast<GroupParamWrapper *>(reinterpret_cast< ::Natron::Python::GroupParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUPPARAM_IDX], reinterpret_cast<SbkObject *>(self))));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: GroupParam::setOpened(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setOpened(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_GroupParamFunc_setOpened_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setOpened(bool)
            // Begin code injection

            cppSelf->setOpened(cppArg0);

            // End of code injection


        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_GroupParamFunc_setOpened_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronEngine.Natron.Python.GroupParam.setOpened");
        return {};
}

static PyMethodDef Sbk_Natron_Python_GroupParam_methods[] = {
    {"addParam", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GroupParamFunc_addParam), METH_O},
    {"getIsOpened", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GroupParamFunc_getIsOpened), METH_NOARGS},
    {"setAsTab", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GroupParamFunc_setAsTab), METH_NOARGS},
    {"setOpened", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_GroupParamFunc_setOpened), METH_O},

    {nullptr, nullptr} // Sentinel
};

static int Sbk_Natron_Python_GroupParam_setattro(PyObject *self, PyObject *name, PyObject *value)
{
    if (value && PyCallable_Check(value)) {
        auto plain_inst = reinterpret_cast< ::Natron::Python::GroupParam *>(Shiboken::Conversions::cppPointer(SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUPPARAM_IDX], reinterpret_cast<SbkObject *>(self)));
        auto inst = dynamic_cast<GroupParamWrapper *>(plain_inst);
        if (inst)
            inst->resetPyMethodCache();
    }
    return PyObject_GenericSetAttr(self, name, value);
}

} // extern "C"

static int Sbk_Natron_Python_GroupParam_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_GroupParam_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_GroupParam_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_GroupParam_TypeF(void)
{
    return _Sbk_Natron_Python_GroupParam_Type;
}

static PyType_Slot Sbk_Natron_Python_GroupParam_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    reinterpret_cast<void *>(Sbk_Natron_Python_GroupParam_setattro)},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_GroupParam_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_GroupParam_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_GroupParam_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_GroupParam_spec = {
    "1:NatronEngine.Natron.Python.GroupParam",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_GroupParam_slots
};

} //extern "C"

static void *Sbk_Natron_Python_GroupParam_typeDiscovery(void *cptr, SbkObjectType *instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType *>(Shiboken::SbkType< ::Natron::Python::Param >()))
        return dynamic_cast< ::Natron::Python::GroupParam *>(reinterpret_cast< ::Natron::Python::Param *>(cptr));
    return {};
}


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void GroupParam_PythonToCpp_GroupParam_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_GroupParam_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_GroupParam_PythonToCpp_GroupParam_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_GroupParam_TypeF())))
        return GroupParam_PythonToCpp_GroupParam_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *GroupParam_PTR_CppToPython_GroupParam(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::GroupParam *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_GroupParam_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_GroupParam_SignatureStrings[] = {
    "NatronEngine.Natron.Python.GroupParam.addParam(param:NatronEngine.Natron.Python.Param)",
    "NatronEngine.Natron.Python.GroupParam.getIsOpened()->bool",
    "NatronEngine.Natron.Python.GroupParam.setAsTab()",
    "NatronEngine.Natron.Python.GroupParam.setOpened(opened:bool)",
    nullptr}; // Sentinel

void init_Natron_Python_GroupParam(PyObject *enclosingClass)
{
    _Sbk_Natron_Python_GroupParam_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "GroupParam",
        "Natron::Python::GroupParam*",
        &Sbk_Natron_Python_GroupParam_spec,
        Natron_Python_GroupParam_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::GroupParam >,
        reinterpret_cast<SbkObjectType *>(SbkNatronEngineTypes[SBK_NATRON_PYTHON_PARAM_IDX]),
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    SbkNatronEngineTypes[SBK_NATRON_PYTHON_GROUPPARAM_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_GroupParam_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_GroupParam_TypeF(),
        GroupParam_PythonToCpp_GroupParam_PTR,
        is_GroupParam_PythonToCpp_GroupParam_PTR_Convertible,
        GroupParam_PTR_CppToPython_GroupParam);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::GroupParam");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::GroupParam*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::GroupParam&");
    Shiboken::Conversions::registerConverterName(converter, "Python::GroupParam");
    Shiboken::Conversions::registerConverterName(converter, "Python::GroupParam*");
    Shiboken::Conversions::registerConverterName(converter, "Python::GroupParam&");
    Shiboken::Conversions::registerConverterName(converter, "GroupParam");
    Shiboken::Conversions::registerConverterName(converter, "GroupParam*");
    Shiboken::Conversions::registerConverterName(converter, "GroupParam&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::GroupParam).name());
    Shiboken::Conversions::registerConverterName(converter, typeid(::GroupParamWrapper).name());


    Shiboken::ObjectType::setTypeDiscoveryFunctionV2(Sbk_Natron_Python_GroupParam_TypeF(), &Sbk_Natron_Python_GroupParam_typeDiscovery);


    GroupParamWrapper::pysideInitQtMetaTypes();
}
