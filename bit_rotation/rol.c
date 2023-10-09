unsigned char rol(unsigned char value, unsigned char roll)
{
    unsigned char roled = value << roll;
    unsigned char leftPart = value >> ((sizeof(unsigned char) * 8) - roll);
    return roled | leftPart;
}
