#ifndef OBJCOUNTER_H
#define OBJCOUNTER_H

template <class T>
class ObjCounter
{
private:
    static inline int totalConstructed{0};
    static inline int totalDestructed{0};
    static inline int objCount{0};
protected:
    ObjCounter()
    {
        ++objCount;
        ++totalConstructed;
    }
    ~ObjCounter()
    {
        --objCount;
        ++totalDestructed;
    }
public:
    static int getObjCount() { return objCount; }
    static int getTotalConstructed() { return totalConstructed; }
    static int getTotalDestructed() { return totalDestructed; }
};

#endif
