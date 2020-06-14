#ifndef SBK_PYCOREAPPLICATIONWRAPPER_H
#define SBK_PYCOREAPPLICATIONWRAPPER_H

#include <PyGlobalFunctions.h>

class PyCoreApplicationWrapper : public PyCoreApplication
{
public:
    PyCoreApplicationWrapper();
    ~PyCoreApplicationWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#endif // SBK_PYCOREAPPLICATIONWRAPPER_H

