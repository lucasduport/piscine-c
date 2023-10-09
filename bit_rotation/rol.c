unsigned char rol(unsigned char value, unsigned char roll)
{
    roll = roll % 8;
    unsigned int roled = value << roll;
    unsigned int leftPart = value >> ((sizeof(unsigned char) * 8) - roll);
    return roled | leftPart;
}
