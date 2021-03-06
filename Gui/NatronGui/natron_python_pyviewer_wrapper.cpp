
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
#include "natron_python_pyviewer_wrapper.h"

// inner classes

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
static PyObject *Sbk_Natron_Python_PyViewerFunc_getAInput(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getAInput()const
            int cppResult = const_cast<const ::Natron::Python::PyViewer *>(cppSelf)->getAInput();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_getBInput(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getBInput()const
            int cppResult = const_cast<const ::Natron::Python::PyViewer *>(cppSelf)->getBInput();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_getChannels(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getChannels()const
            Natron::DisplayChannelsEnum cppResult = const_cast<const ::Natron::Python::PyViewer *>(cppSelf)->getChannels();
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_getCompositingOperator(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCompositingOperator()const
            Natron::ViewerCompositingOperatorEnum cppResult = const_cast<const ::Natron::Python::PyViewer *>(cppSelf)->getCompositingOperator();
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_getCurrentFrame(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCurrentFrame()
            int cppResult = cppSelf->getCurrentFrame();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_getCurrentView(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getCurrentView()const
            int cppResult = const_cast<const ::Natron::Python::PyViewer *>(cppSelf)->getCurrentView();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_getFrameRange(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getFrameRange(int*,int*)const
            // Begin code injection

            int x,y;
            cppSelf->getFrameRange(&x,&y);
            pyResult = PyTuple_New(2);
            PyTuple_SET_ITEM(pyResult, 0, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &x));
            PyTuple_SET_ITEM(pyResult, 1, Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &y));
            return pyResult;

            // End of code injection


        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_getPlaybackMode(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getPlaybackMode()const
            Natron::PlaybackModeEnum cppResult = const_cast<const ::Natron::Python::PyViewer *>(cppSelf)->getPlaybackMode();
            pyResult = Shiboken::Conversions::copyToPython(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX])->converter, &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_getProxyIndex(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // getProxyIndex()const
            int cppResult = const_cast<const ::Natron::Python::PyViewer *>(cppSelf)->getProxyIndex();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<int>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_isProxyModeEnabled(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    PyObject *pyResult{};

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // isProxyModeEnabled()const
            bool cppResult = const_cast<const ::Natron::Python::PyViewer *>(cppSelf)->isProxyModeEnabled();
            pyResult = Shiboken::Conversions::copyToPython(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), &cppResult);
        }
    }

    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return {};
    }
    return pyResult;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_pause(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // pause()
            cppSelf->pause();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_redraw(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // redraw()
            cppSelf->redraw();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_renderCurrentFrame(PyObject *self, PyObject *args, PyObject *kwds)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr };
    SBK_UNUSED(pythonToCpp)
    int numNamedArgs = (kwds ? PyDict_Size(kwds) : 0);
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0};

    // invalid argument lengths
    if (numArgs + numNamedArgs > 1) {
        PyErr_SetString(PyExc_TypeError, "NatronGui.Natron.Python.PyViewer.renderCurrentFrame(): too many arguments");
        return {};
    }

    if (!PyArg_ParseTuple(args, "|O:renderCurrentFrame", &(pyArgs[0])))
        return {};


    // Overloaded function decisor
    // 0: PyViewer::renderCurrentFrame(bool)
    if (numArgs == 0) {
        overloadId = 0; // renderCurrentFrame(bool)
    } else if ((pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0])))) {
        overloadId = 0; // renderCurrentFrame(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_renderCurrentFrame_TypeError;

    // Call function/method
    {
        if (kwds) {
            PyObject *keyName = nullptr;
            PyObject *value = nullptr;
            keyName = Py_BuildValue("s","useCache");
            if (PyDict_Contains(kwds, keyName)) {
                value = PyDict_GetItem(kwds, keyName);
                if (value && pyArgs[0]) {
                    PyErr_SetString(PyExc_TypeError, "NatronGui.Natron.Python.PyViewer.renderCurrentFrame(): got multiple values for keyword argument 'useCache'.");
                    return {};
                }
                if (value) {
                    pyArgs[0] = value;
                    if (!(pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArgs[0]))))
                        goto Sbk_Natron_Python_PyViewerFunc_renderCurrentFrame_TypeError;
                }
            }
        }
        bool cppArg0 = true;
        if (pythonToCpp[0]) pythonToCpp[0](pyArgs[0], &cppArg0);

        if (!PyErr_Occurred()) {
            // renderCurrentFrame(bool)
            cppSelf->renderCurrentFrame(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_renderCurrentFrame_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.Natron.Python.PyViewer.renderCurrentFrame");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_seek(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::seek(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // seek(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_seek_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // seek(int)
            cppSelf->seek(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_seek_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.seek");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setAInput(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::setAInput(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setAInput(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setAInput_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setAInput(int)
            cppSelf->setAInput(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setAInput_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.setAInput");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setBInput(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::setBInput(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setBInput(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setBInput_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setBInput(int)
            cppSelf->setBInput(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setBInput_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.setBInput");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setChannels(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::setChannels(Natron::DisplayChannelsEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_DISPLAYCHANNELSENUM_IDX])->converter, (pyArg)))) {
        overloadId = 0; // setChannels(Natron::DisplayChannelsEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setChannels_TypeError;

    // Call function/method
    {
        ::Natron::DisplayChannelsEnum cppArg0 = static_cast< ::Natron::DisplayChannelsEnum>(0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setChannels(Natron::DisplayChannelsEnum)
            cppSelf->setChannels(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setChannels_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.setChannels");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setCompositingOperator(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::setCompositingOperator(Natron::ViewerCompositingOperatorEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_VIEWERCOMPOSITINGOPERATORENUM_IDX])->converter, (pyArg)))) {
        overloadId = 0; // setCompositingOperator(Natron::ViewerCompositingOperatorEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setCompositingOperator_TypeError;

    // Call function/method
    {
        ::Natron::ViewerCompositingOperatorEnum cppArg0 = static_cast< ::Natron::ViewerCompositingOperatorEnum>(0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCompositingOperator(Natron::ViewerCompositingOperatorEnum)
            cppSelf->setCompositingOperator(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setCompositingOperator_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.setCompositingOperator");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setCurrentView(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::setCurrentView(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setCurrentView(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setCurrentView_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setCurrentView(int)
            cppSelf->setCurrentView(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setCurrentView_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.setCurrentView");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setFrameRange(PyObject *self, PyObject *args)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp[] = { nullptr, nullptr };
    SBK_UNUSED(pythonToCpp)
    int numArgs = PyTuple_GET_SIZE(args);
    SBK_UNUSED(numArgs)
    PyObject *pyArgs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setFrameRange", 2, 2, &(pyArgs[0]), &(pyArgs[1])))
        return {};


    // Overloaded function decisor
    // 0: PyViewer::setFrameRange(int,int)
    if (numArgs == 2
        && (pythonToCpp[0] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[0])))
        && (pythonToCpp[1] = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArgs[1])))) {
        overloadId = 0; // setFrameRange(int,int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setFrameRange_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp[0](pyArgs[0], &cppArg0);
        int cppArg1;
        pythonToCpp[1](pyArgs[1], &cppArg1);

        if (!PyErr_Occurred()) {
            // setFrameRange(int,int)
            cppSelf->setFrameRange(cppArg0, cppArg1);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setFrameRange_TypeError:
        Shiboken::setErrorAboutWrongArguments(args, "NatronGui.Natron.Python.PyViewer.setFrameRange");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setPlaybackMode(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::setPlaybackMode(Natron::PlaybackModeEnum)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(*PepType_SGTP(SbkNatronEngineTypes[SBK_NATRON_PLAYBACKMODEENUM_IDX])->converter, (pyArg)))) {
        overloadId = 0; // setPlaybackMode(Natron::PlaybackModeEnum)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setPlaybackMode_TypeError;

    // Call function/method
    {
        ::Natron::PlaybackModeEnum cppArg0 = static_cast< ::Natron::PlaybackModeEnum>(0);
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setPlaybackMode(Natron::PlaybackModeEnum)
            cppSelf->setPlaybackMode(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setPlaybackMode_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.setPlaybackMode");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setProxyIndex(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::setProxyIndex(int)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<int>(), (pyArg)))) {
        overloadId = 0; // setProxyIndex(int)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setProxyIndex_TypeError;

    // Call function/method
    {
        int cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProxyIndex(int)
            cppSelf->setProxyIndex(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setProxyIndex_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.setProxyIndex");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_setProxyModeEnabled(PyObject *self, PyObject *pyArg)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)
    int overloadId = -1;
    PythonToCppFunc pythonToCpp{};
    SBK_UNUSED(pythonToCpp)

    // Overloaded function decisor
    // 0: PyViewer::setProxyModeEnabled(bool)
    if ((pythonToCpp = Shiboken::Conversions::isPythonToCppConvertible(Shiboken::Conversions::PrimitiveTypeConverter<bool>(), (pyArg)))) {
        overloadId = 0; // setProxyModeEnabled(bool)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_Natron_Python_PyViewerFunc_setProxyModeEnabled_TypeError;

    // Call function/method
    {
        bool cppArg0;
        pythonToCpp(pyArg, &cppArg0);

        if (!PyErr_Occurred()) {
            // setProxyModeEnabled(bool)
            cppSelf->setProxyModeEnabled(cppArg0);
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;

    Sbk_Natron_Python_PyViewerFunc_setProxyModeEnabled_TypeError:
        Shiboken::setErrorAboutWrongArguments(pyArg, "NatronGui.Natron.Python.PyViewer.setProxyModeEnabled");
        return {};
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_startBackward(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startBackward()
            cppSelf->startBackward();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyObject *Sbk_Natron_Python_PyViewerFunc_startForward(PyObject *self)
{
    if (!Shiboken::Object::isValid(self))
        return {};
    auto cppSelf = reinterpret_cast< ::Natron::Python::PyViewer *>(Shiboken::Conversions::cppPointer(SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX], reinterpret_cast<SbkObject *>(self)));
    SBK_UNUSED(cppSelf)

    // Call function/method
    {

        if (!PyErr_Occurred()) {
            // startForward()
            cppSelf->startForward();
        }
    }

    if (PyErr_Occurred()) {
        return {};
    }
    Py_RETURN_NONE;
}

static PyMethodDef Sbk_Natron_Python_PyViewer_methods[] = {
    {"getAInput", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getAInput), METH_NOARGS},
    {"getBInput", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getBInput), METH_NOARGS},
    {"getChannels", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getChannels), METH_NOARGS},
    {"getCompositingOperator", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getCompositingOperator), METH_NOARGS},
    {"getCurrentFrame", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getCurrentFrame), METH_NOARGS},
    {"getCurrentView", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getCurrentView), METH_NOARGS},
    {"getFrameRange", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getFrameRange), METH_NOARGS},
    {"getPlaybackMode", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getPlaybackMode), METH_NOARGS},
    {"getProxyIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_getProxyIndex), METH_NOARGS},
    {"isProxyModeEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_isProxyModeEnabled), METH_NOARGS},
    {"pause", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_pause), METH_NOARGS},
    {"redraw", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_redraw), METH_NOARGS},
    {"renderCurrentFrame", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_renderCurrentFrame), METH_VARARGS|METH_KEYWORDS},
    {"seek", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_seek), METH_O},
    {"setAInput", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setAInput), METH_O},
    {"setBInput", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setBInput), METH_O},
    {"setChannels", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setChannels), METH_O},
    {"setCompositingOperator", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setCompositingOperator), METH_O},
    {"setCurrentView", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setCurrentView), METH_O},
    {"setFrameRange", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setFrameRange), METH_VARARGS},
    {"setPlaybackMode", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setPlaybackMode), METH_O},
    {"setProxyIndex", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setProxyIndex), METH_O},
    {"setProxyModeEnabled", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_setProxyModeEnabled), METH_O},
    {"startBackward", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_startBackward), METH_NOARGS},
    {"startForward", reinterpret_cast<PyCFunction>(Sbk_Natron_Python_PyViewerFunc_startForward), METH_NOARGS},

    {nullptr, nullptr} // Sentinel
};

} // extern "C"

static int Sbk_Natron_Python_PyViewer_traverse(PyObject *self, visitproc visit, void *arg)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_traverse(self, visit, arg);
}
static int Sbk_Natron_Python_PyViewer_clear(PyObject *self)
{
    return reinterpret_cast<PyTypeObject *>(SbkObject_TypeF())->tp_clear(self);
}
// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType *_Sbk_Natron_Python_PyViewer_Type = nullptr;
static SbkObjectType *Sbk_Natron_Python_PyViewer_TypeF(void)
{
    return _Sbk_Natron_Python_PyViewer_Type;
}

static PyType_Slot Sbk_Natron_Python_PyViewer_slots[] = {
    {Py_tp_base,        nullptr}, // inserted by introduceWrapperType
    {Py_tp_dealloc,     reinterpret_cast<void *>(&SbkDeallocWrapper)},
    {Py_tp_repr,        nullptr},
    {Py_tp_hash,        nullptr},
    {Py_tp_call,        nullptr},
    {Py_tp_str,         nullptr},
    {Py_tp_getattro,    nullptr},
    {Py_tp_setattro,    nullptr},
    {Py_tp_traverse,    reinterpret_cast<void *>(Sbk_Natron_Python_PyViewer_traverse)},
    {Py_tp_clear,       reinterpret_cast<void *>(Sbk_Natron_Python_PyViewer_clear)},
    {Py_tp_richcompare, nullptr},
    {Py_tp_iter,        nullptr},
    {Py_tp_iternext,    nullptr},
    {Py_tp_methods,     reinterpret_cast<void *>(Sbk_Natron_Python_PyViewer_methods)},
    {Py_tp_getset,      nullptr},
    {Py_tp_init,        nullptr},
    {Py_tp_new,         reinterpret_cast<void *>(SbkDummyNew /* PYSIDE-595: Prevent replacement of "0" with base->tp_new. */)},
    {0, nullptr}
};
static PyType_Spec Sbk_Natron_Python_PyViewer_spec = {
    "1:NatronGui.Natron.Python.PyViewer",
    sizeof(SbkObject),
    0,
    Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_GC,
    Sbk_Natron_Python_PyViewer_slots
};

} //extern "C"


// Type conversion functions.

// Python to C++ pointer conversion - returns the C++ object of the Python wrapper (keeps object identity).
static void PyViewer_PythonToCpp_PyViewer_PTR(PyObject *pyIn, void *cppOut) {
    Shiboken::Conversions::pythonToCppPointer(Sbk_Natron_Python_PyViewer_TypeF(), pyIn, cppOut);
}
static PythonToCppFunc is_PyViewer_PythonToCpp_PyViewer_PTR_Convertible(PyObject *pyIn) {
    if (pyIn == Py_None)
        return Shiboken::Conversions::nonePythonToCppNullPtr;
    if (PyObject_TypeCheck(pyIn, reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_PyViewer_TypeF())))
        return PyViewer_PythonToCpp_PyViewer_PTR;
    return {};
}

// C++ to Python pointer conversion - tries to find the Python wrapper for the C++ object (keeps object identity).
static PyObject *PyViewer_PTR_CppToPython_PyViewer(const void *cppIn) {
    auto pyOut = reinterpret_cast<PyObject *>(Shiboken::BindingManager::instance().retrieveWrapper(cppIn));
    if (pyOut) {
        Py_INCREF(pyOut);
        return pyOut;
    }
    bool changedTypeName = false;
    auto tCppIn = reinterpret_cast<const ::Natron::Python::PyViewer *>(cppIn);
    const char *typeName = typeid(*tCppIn).name();
    auto sbkType = Shiboken::ObjectType::typeForTypeName(typeName);
    if (sbkType && Shiboken::ObjectType::hasSpecialCastFunction(sbkType)) {
        typeName = typeNameOf(tCppIn);
        changedTypeName = true;
     }
    PyObject *result = Shiboken::Object::newObject(Sbk_Natron_Python_PyViewer_TypeF(), const_cast<void *>(cppIn), false, /* exactType */ changedTypeName, typeName);
    if (changedTypeName)
        delete [] typeName;
    return result;
}

// The signatures string for the functions.
// Multiple signatures have their index "n:" in front.
static const char *Natron_Python_PyViewer_SignatureStrings[] = {
    "NatronGui.Natron.Python.PyViewer.getAInput()->int",
    "NatronGui.Natron.Python.PyViewer.getBInput()->int",
    "NatronGui.Natron.Python.PyViewer.getChannels()->NatronEngine.Natron.DisplayChannelsEnum",
    "NatronGui.Natron.Python.PyViewer.getCompositingOperator()->NatronEngine.Natron.ViewerCompositingOperatorEnum",
    "NatronGui.Natron.Python.PyViewer.getCurrentFrame()->int",
    "NatronGui.Natron.Python.PyViewer.getCurrentView()->int",
    "NatronGui.Natron.Python.PyViewer.getFrameRange(firstFrame:int*,lastFrame:int*)",
    "NatronGui.Natron.Python.PyViewer.getPlaybackMode()->NatronEngine.Natron.PlaybackModeEnum",
    "NatronGui.Natron.Python.PyViewer.getProxyIndex()->int",
    "NatronGui.Natron.Python.PyViewer.isProxyModeEnabled()->bool",
    "NatronGui.Natron.Python.PyViewer.pause()",
    "NatronGui.Natron.Python.PyViewer.redraw()",
    "NatronGui.Natron.Python.PyViewer.renderCurrentFrame(useCache:bool=true)",
    "NatronGui.Natron.Python.PyViewer.seek(frame:int)",
    "NatronGui.Natron.Python.PyViewer.setAInput(index:int)",
    "NatronGui.Natron.Python.PyViewer.setBInput(index:int)",
    "NatronGui.Natron.Python.PyViewer.setChannels(channels:NatronEngine.Natron.DisplayChannelsEnum)",
    "NatronGui.Natron.Python.PyViewer.setCompositingOperator(op:NatronEngine.Natron.ViewerCompositingOperatorEnum)",
    "NatronGui.Natron.Python.PyViewer.setCurrentView(index:int)",
    "NatronGui.Natron.Python.PyViewer.setFrameRange(firstFrame:int,lastFrame:int)",
    "NatronGui.Natron.Python.PyViewer.setPlaybackMode(mode:NatronEngine.Natron.PlaybackModeEnum)",
    "NatronGui.Natron.Python.PyViewer.setProxyIndex(index:int)",
    "NatronGui.Natron.Python.PyViewer.setProxyModeEnabled(enabled:bool)",
    "NatronGui.Natron.Python.PyViewer.startBackward()",
    "NatronGui.Natron.Python.PyViewer.startForward()",
    nullptr}; // Sentinel

void init_Natron_Python_PyViewer(PyObject *enclosingClass)
{
    _Sbk_Natron_Python_PyViewer_Type = Shiboken::ObjectType::introduceWrapperType(
        enclosingClass,
        "PyViewer",
        "Natron::Python::PyViewer*",
        &Sbk_Natron_Python_PyViewer_spec,
        Natron_Python_PyViewer_SignatureStrings,
        &Shiboken::callCppDestructor< ::Natron::Python::PyViewer >,
        0,
        0,
        Shiboken::ObjectType::WrapperFlags::InnerClass    );
    
    SbkNatronGuiTypes[SBK_NATRON_PYTHON_PYVIEWER_IDX]
        = reinterpret_cast<PyTypeObject *>(Sbk_Natron_Python_PyViewer_TypeF());

    // Register Converter
    SbkConverter *converter = Shiboken::Conversions::createConverter(Sbk_Natron_Python_PyViewer_TypeF(),
        PyViewer_PythonToCpp_PyViewer_PTR,
        is_PyViewer_PythonToCpp_PyViewer_PTR_Convertible,
        PyViewer_PTR_CppToPython_PyViewer);

    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyViewer");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyViewer*");
    Shiboken::Conversions::registerConverterName(converter, "Natron::Python::PyViewer&");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyViewer");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyViewer*");
    Shiboken::Conversions::registerConverterName(converter, "Python::PyViewer&");
    Shiboken::Conversions::registerConverterName(converter, "PyViewer");
    Shiboken::Conversions::registerConverterName(converter, "PyViewer*");
    Shiboken::Conversions::registerConverterName(converter, "PyViewer&");
    Shiboken::Conversions::registerConverterName(converter, typeid(::Natron::Python::PyViewer).name());



}
