#ifndef SBK_USERPARAMHOLDERWRAPPER_H
#define SBK_USERPARAMHOLDERWRAPPER_H

#include <PyNode.h>

class UserParamHolderWrapper : public Natron::Python::UserParamHolder
{
public:
    UserParamHolderWrapper();
    ~UserParamHolderWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#endif // SBK_USERPARAMHOLDERWRAPPER_H

