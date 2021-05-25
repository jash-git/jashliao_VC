unsigned char atoh(unsigned char character)
{
   if(character >= 0x30 && character <= 0x39)
     return(character - 0x30);
   else if(character >= 0x41 && character <= 0x46)
     return(character - 0x37);
}

