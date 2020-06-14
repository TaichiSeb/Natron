#ifndef SBK_PYGUIAPPLICATIONWRAPPER_H
#define SBK_PYGUIAPPLICATIONWRAPPER_H

#include <PyGlobalGui.h>

class PyGuiApplicationWrapper : public PyGuiApplication
{
public:
    PyGuiApplicationWrapper();
    ~PyGuiApplicationWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#endif // SBK_PYGUIAPPLICATIONWRAPPER_H

