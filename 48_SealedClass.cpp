

class SealedClass1
{
public:
    static SealedClass1* GetInstance() {
        return new SealedClass1();
    }

    static void DeleteInstance(SealedClass1 *pInstance) {
        if(pInstance != NULL)
            delete pInstance;
    }

private:
    SealedClass1() {}
    ~SealedClass1() {}

    /* data */
};


template<typename T> class MakeSealed {
    friend T;

private:
    MakeSealed() {}
    ~MakeSealed() {}
};


class SealedClass2 : virtual public MakeSealed<SealedClass2> {
public:
    SealedClass2() {}
    ~SealedClass2() {}
};