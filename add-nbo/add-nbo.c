#include <stddef.h> // for size_t
#include <stdint.h> // for uint8_t
#include <stdio.h> // for printf
#include <netinet/in.h>





int main(int argc, char *argv[])
{
    // uint32_t* p = reinterpret_cast<uint32_t*> (network_buffer);
    FILE  *fp, *fc;
    fp = fopen(argv[1], "rb");
    if(fp ==NULL)
    {
        printf("not file open ");
    }
   // uint32_t *p = reinterpret_cast<uint32_t*>(fp);
    uint32_t p;
    fread(&p, 4, 1, fp);
    uint32_t a2 = ntohl(p);


    fc = fopen(argv[2], "rb");
    //uint32_t* p2  = reinterpret_cast<uint32_t*>(fc);
    uint32_t p2;
    fread(&p2, 4, 1, fc);
    uint32_t b2 = ntohl(p2);

    uint32_t sum = a2+b2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a2, a2, b2, b2, sum, sum);


    fclose(fp);
    fclose(fc);
    return 0;
}
