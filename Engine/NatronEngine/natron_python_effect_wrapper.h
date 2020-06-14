#ifndef SBK_EFFECTWRAPPER_H
#define SBK_EFFECTWRAPPER_H

#include <PyNode.h>

class EffectWrapper : public Natron::Python::Effect
{
public:
    ~EffectWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_GROUPWRAPPER_H
#  define SBK_GROUPWRAPPER_H

// Inherited base class:
class GroupWrapper : public Natron::Python::Group
{
public:
    GroupWrapper();
    ~GroupWrapper();
    static void pysideInitQtMetaTypes();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_GROUPWRAPPER_H

#endif // SBK_EFFECTWRAPPER_H

