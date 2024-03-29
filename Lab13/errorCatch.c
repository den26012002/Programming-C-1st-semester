#include "errorCatch.h"

int checkIdentifier(const char* identifier) {
    char* probablyIdentifiers[] = {
   "BUF\0",
   "CNT\0",
   "COM\0",
   "CRA\0",
   "CRM\0",
   "ETC\0",
   "EQU\0",
   "GEO\0",
   "IPL\0",
   "LNK\0",
   "MCI\0",
   "MLL\0",
   "PIC\0",
   "POP\0",
   "REV\0",
   "RVA\0",
   "SLT\0",
   "STC\0",
   "TAL\0",
   "TBP\0",
   "TCM\0",
   "TCO\0",
   "TCR\0",
   "TDA\0",
   "TDY\0",
   "TEN\0",
   "TFT\0",
   "TIM\0",
   "TKE\0",
   "TLA\0",
   "TLE\0",
   "TMT\0",
   "TOA\0",
   "TOF\0",
   "TOL\0",
   "TOR\0",
   "TOT\0",
   "TP1\0",
   "TP2\0",
   "TP3\0",
   "TP4\0",
   "TPA\0",
   "TPB\0",
   "TRC\0",
   "TRD\0",
   "TRK\0",
   "TSI\0",
   "TSS\0",
   "TT1\0",
   "TT2\0",
   "TT3\0",
   "TXT\0",
   "TXX\0",
   "TYE\0",
   "UFI\0",
   "ULT\0",
   "WAF\0",
   "WAR\0",
   "WAS\0",
   "WCM\0",
   "WCP\0",
   "WPB\0",
   "WXX\0"
   };
    int ans = 0;
    for (int i = 0; i < 63; i++) {
        if (!strcmp(identifier, probablyIdentifiers[i])) {
            ans = 1;
        }
    }
    return ans;
}
