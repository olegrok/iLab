unsigned int HashFAQ6(const char * str)
{

    unsigned int hash = 0;

    for (; *str; str++)
    {
        hash += (unsigned char)(*str);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;

}


unsigned int HashRot13(const char * str)
{

    unsigned int hash = 0;

    for(; *str; str++)
    {
        hash += (unsigned char)(*str);
        hash -= (hash << 13) | (hash >> 19);
    }

    return hash;

}


unsigned int HashLy(const char * str)
{

    unsigned int hash = 0;

    for(; *str; str++)
        hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;

    return hash;

}


unsigned int HashRs(const char * str)
{

    static const unsigned int b = 378551;
    unsigned int a = 63689;
    unsigned int hash = 0;

    for(; *str; str++)
    {
        hash = hash * a + (unsigned char)(*str);
        a *= b;
    }

    return hash;

}
