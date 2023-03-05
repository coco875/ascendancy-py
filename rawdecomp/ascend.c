typedef unsigned char   undefined;

typedef unsigned char    undefined1;
typedef unsigned int    undefined2;
typedef unsigned long    undefined4;
typedef unsigned int    word;
typedef struct OLD_IMAGE_DOS_RELOC OLD_IMAGE_DOS_RELOC, *POLD_IMAGE_DOS_RELOC;

struct OLD_IMAGE_DOS_RELOC {
    word offset;
    word segment;
};

typedef struct OLD_IMAGE_DOS_HEADER OLD_IMAGE_DOS_HEADER, *POLD_IMAGE_DOS_HEADER;

struct OLD_IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
};




undefined4 /*__cdecl16near*/ FUN_1000_0008(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  undefined2 in_DX;
  char *pcVar5;
  undefined2 uVar6;
  undefined2 unaff_DS;
  
  pcVar3 = (char *)FUN_1000_00b5();
  if (pcVar3 != (char *)0x0) {
    pcVar5 = (char *)0x3ce;
    do {
      pcVar1 = pcVar3;
      pcVar3 = pcVar3 + 1;
      cVar2 = *pcVar1;
      *pcVar5 = cVar2;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    uVar6 = 0x3ce;
    FUN_1000_0103();
    iVar4 = FUN_1000_0121();
    if (iVar4 != 0) goto LAB_1000_0061;
  }
  for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 2) {
    FUN_1000_019f();
    if (*(char *)0x3ce != '\0') {
      uVar6 = 0x3ce;
      goto LAB_1000_0061;
    }
  }
  uVar6 = 0x36;
LAB_1000_0061:
  return CONCAT22(in_DX,uVar6);
}



void FUN_1000_0066(void)

{
  FUN_1000_0008();
  FUN_1000_0278();
  FUN_1000_02a9();
  FUN_1000_02b3();
  FUN_1000_02b3();
  FUN_1000_02d1();
  FUN_1000_02d9();
  FUN_1000_02b3();
  FUN_1000_02f3();
  return;
}



undefined4 /*__cdecl16near*/ FUN_1000_00b5(void)

{
  int in_AX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined2 in_DX;
  int *piVar4;
  undefined2 unaff_DS;
  
  piVar4 = *(int **)0x1f0;
  if ((piVar4 != (int *)0x0) && (in_AX != 0)) {
    iVar1 = FUN_1000_0586();
    for (; iVar3 = *piVar4, iVar3 != 0; piVar4 = piVar4 + 1) {
      iVar2 = FUN_1000_059f();
      if ((iVar2 == 0) && (*(char *)(iVar3 + iVar1) == '=')) {
        iVar3 = iVar1 + 1 + iVar3;
        goto LAB_1000_00fa;
      }
    }
  }
  iVar3 = 0;
LAB_1000_00fa:
  return CONCAT22(in_DX,iVar3);
}



void /*__cdecl16near*/ FUN_1000_0103(void)

{
  char cVar1;
  char *in_AX;
  undefined2 unaff_DS;
  
  for (; cVar1 = *in_AX, cVar1 != '\0'; in_AX = in_AX + 1) {
    if ((byte)(cVar1 + 0xbfU) < 0x1a) {
      *in_AX = cVar1 + ' ';
    }
  }
  return;
}



void /*__cdecl16near*/ FUN_1000_0121(void)

{
  char *in_AX;
  int iVar1;
  int iVar2;
  int iVar3;
  char *in_DX;
  char *pcVar4;
  char *pcVar5;
  undefined2 unaff_DS;
  byte in_AF;
  bool bVar6;
  
  if (*in_DX != '\0') {
    if (in_DX[1] == '\0') {
      FUN_1000_05ea();
    }
    else {
      iVar1 = FUN_1000_0618();
      iVar2 = FUN_1000_0586();
      for (; iVar2 <= iVar1 - (int)in_AX; in_AX = in_AX + 1) {
        in_AX = (char *)FUN_1000_0618();
        bVar6 = in_AX == (char *)0x0;
        iVar3 = iVar2;
        pcVar4 = in_AX;
        pcVar5 = in_DX;
        if (bVar6) {
          return;
        }
        do {
          if (iVar3 == 0) break;
          bVar6 = *pcVar4 == *pcVar5;
          iVar3 = iVar3 + -1;
          pcVar4 = pcVar4 + 1;
          pcVar5 = pcVar5 + 1;
        } while (bVar6);
        if ((byte)(bVar6 << 6 | (in_AF & 4) << 4) != 0) {
          return;
        }
      }
    }
  }
  return;
}



void /*__cdecl16near*/ FUN_1000_019f(void)

{
  char *in_AX;
  undefined2 *puVar1;
  int iVar2;
  char *pcVar3;
  undefined2 uVar4;
  char *in_BX;
  char *pcVar5;
  undefined2 unaff_DS;
  
  puVar1 = (undefined2 *)FUN_1000_02d1();
  uVar4 = *puVar1;
  iVar2 = FUN_1000_0635();
  if (iVar2 == 0) {
    if (((*in_AX != '\\') && (*in_AX != '.')) &&
       ((*in_AX != '/' && ((*in_AX == '\0' || (in_AX[1] != ':')))))) {
      FUN_1000_0658();
      iVar2 = FUN_1000_0586();
      if ((in_BX + iVar2)[-1] != '\\') {
        in_BX[iVar2] = '\\';
      }
    }
    FUN_1000_06cf();
  }
  else {
    pcVar3 = (char *)FUN_1000_00b5();
    if (pcVar3 != (char *)0x0) {
      for (; pcVar5 = in_BX, *pcVar3 != '\0'; pcVar3 = pcVar3 + 1) {
        for (; (*pcVar3 != '\0' && (*pcVar3 != ';')); pcVar3 = pcVar3 + 1) {
          *pcVar5 = *pcVar3;
          pcVar5 = pcVar5 + 1;
        }
        if (pcVar5 != in_BX) {
          if (((pcVar5[-1] != '\\') && (pcVar5[-1] != '/')) && (pcVar5[-1] != ':')) {
            *pcVar5 = '\\';
            pcVar5 = pcVar5 + 1;
          }
          *pcVar5 = '\0';
          FUN_1000_070e();
          iVar2 = FUN_1000_0635();
          if (iVar2 == 0) {
            puVar1 = (undefined2 *)FUN_1000_02d1();
            *puVar1 = uVar4;
            return;
          }
        }
        if (*pcVar3 == '\0') break;
      }
    }
    *in_BX = '\0';
  }
  return;
}



void /*__cdecl16near*/ FUN_1000_0278(void)

{
  undefined *puVar1;
  undefined2 uVar2;
  undefined *in_AX;
  uint uVar3;
  undefined *puVar4;
  undefined2 unaff_DS;
  
  uVar2 = *(undefined2 *)0x1f6;
  puVar4 = (undefined *)0x81;
  for (uVar3 = (uint)*(byte *)0x80; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar1 = puVar4;
    puVar4 = puVar4 + 1;
    *in_AX = *puVar1;
    in_AX = in_AX + 1;
  }
  *in_AX = 0;
  return;
}



void /*__cdecl16near*/ FUN_1000_02a9(void)

{
  FUN_1000_0741();
  return;
}



int /*__cdecl16near*/ FUN_1000_02b3(void)

{
  int iVar1;
  
  iVar1 = FUN_1000_0838();
  if (iVar1 != -1) {
    iVar1 = FUN_1000_0893();
    if (iVar1 == 10) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



undefined2 /*__cdecl16near*/ FUN_1000_02d1(void)

{
  return 0x41e;
}



undefined2 /*__cdecl16near*/ FUN_1000_02d5(void)

{
  return 0x420;
}



undefined2 /*__cdecl16near*/ FUN_1000_02d9(void)

{
  int in_AX;
  undefined2 uVar1;
  undefined2 unaff_DS;
  
  if ((in_AX < 0) || (0xf < in_AX)) {
    uVar1 = 0x183;
  }
  else {
    uVar1 = *(undefined2 *)(in_AX * 2 + 0x1c4);
  }
  return uVar1;
}



// WARNING: This function may have set the stack pointer

undefined2 FUN_1000_02f3(void)

{
  char *pcVar1;
  int *piVar2;
  code *pcVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 extraout_DX;
  int *piVar6;
  undefined2 unaff_SS;
  undefined2 unaff_DS;
  undefined in_ZF;
  char *pcVar7;
  
  (**(code **)0x1e4)();
  pcVar7 = (char *)0x2fd;
  (**(code **)0x1e6)();
  (**(code **)0x1e6)();
  (**(code **)0x1e8)();
  piVar6 = (int *)0x0;
  iVar5 = 0x10;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    piVar2 = piVar6;
    piVar6 = piVar6 + 1;
    in_ZF = *piVar2 == 0x101;
  } while ((bool)in_ZF);
  if (!(bool)in_ZF) {
    *(undefined2 *)0x4aa = extraout_DX;
    *(undefined2 *)0x4a8 = 0x3a1;
    *(undefined2 *)0x4a6 = 0x1000;
    pcVar3 = (code *)swi(0x21);
    (*pcVar3)();
    do {
      pcVar1 = pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (*pcVar1 != '\0');
    pcVar3 = (code *)swi(0x21);
    (*pcVar3)();
  }
  FUN_1000_099c();
  pcVar3 = (code *)swi(0x21);
  uVar4 = (*pcVar3)();
  return uVar4;
}



// WARNING: Stack frame is not setup normally: Input value of stackpointer is not used
// WARNING: This function may have set the stack pointer
// WARNING: Removing unreachable block (ram,0x0001043d)

undefined2 entry(void)

{
  uint *puVar1;
  char *pcVar2;
  char *pcVar3;
  undefined *puVar4;
  int *piVar5;
  char cVar6;
  code *pcVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  undefined2 uVar11;
  undefined *puVar12;
  undefined2 *puVar13;
  undefined2 *puVar14;
  undefined2 *puVar15;
  int unaff_BP;
  uint *puVar16;
  uint *puVar17;
  char *pcVar18;
  undefined *puVar19;
  int *piVar20;
  int unaff_DS;
  undefined uVar21;
  
  DAT_1262_01fc = (char *)0x430;
  puVar12 = (undefined *)0xc30;
  DAT_1262_01fe = 0xc30;
  uVar21 = DAT_1262_01fa == '\0';
  DAT_1262_01f6 = unaff_DS;
  if ((bool)uVar21) {
    if (0xc3 < *(int *)0x2 + 0xed9eU) {
      DAT_1262_01f4 = 0xc30;
      uVar21 = unaff_DS == 0x1325;
      pcVar7 = (code *)swi(0x21);
      (*pcVar7)();
      goto LAB_1000_0455;
    }
    uVar11 = 1;
    DAT_1262_04a8 = 0x3c2;
  }
  else {
LAB_1000_0455:
    pcVar10 = (char *)0x81;
    uVar8 = (uint)*(byte *)0x80;
    do {
      if (uVar8 == 0) break;
      uVar8 = uVar8 - 1;
      pcVar2 = pcVar10;
      pcVar10 = pcVar10 + 1;
      uVar21 = *pcVar2 == ' ';
    } while ((bool)uVar21);
    pcVar10 = pcVar10 + -1;
    DAT_1262_0216 = DAT_1262_01fc;
    DAT_1262_0218 = 0x1262;
    pcVar18 = DAT_1262_01fc;
    if (!(bool)uVar21) {
      for (iVar9 = uVar8 + 1; iVar9 != 0; iVar9 = iVar9 + -1) {
        pcVar3 = pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar2 = pcVar10;
        pcVar10 = pcVar10 + 1;
        *pcVar3 = *pcVar2;
      }
    }
    *pcVar18 = '\0';
    pcVar18[1] = '\0';
    pcVar18 = pcVar18 + 1;
    pcVar7 = (code *)swi(0x21);
    uVar11 = (*pcVar7)();
    DAT_1262_01f8 = (byte)uVar11;
    DAT_1262_01f9 = (undefined)((uint)uVar11 >> 8);
    DAT_1262_01fc = pcVar18;
    if (2 < DAT_1262_01f8) {
      uVar11 = *(undefined2 *)0x2c;
      puVar16 = (uint *)0x0;
      unaff_BP = 0;
      do {
        if (((*puVar16 | 0x2020) == 0x6f6e) && (puVar16[1] == 0x3738)) {
          unaff_BP = unaff_BP + 1;
        }
        do {
          puVar17 = puVar16;
          puVar16 = (uint *)((int)puVar17 + 1);
        } while (*(char *)puVar17 != '\0');
      } while (*(char *)puVar16 != '\0');
      puVar17 = puVar17 + 2;
      do {
        cVar6 = *(char *)puVar17;
        pcVar2 = DAT_1262_01fc;
        DAT_1262_01fc = DAT_1262_01fc + 1;
        puVar1 = puVar17;
        puVar17 = (uint *)((int)puVar17 + 1);
        *pcVar2 = *(char *)puVar1;
      } while (cVar6 != '\0');
    }
    DAT_1262_021c = 0x1262;
    puVar19 = (undefined *)0x3ce;
    DAT_1262_0204 = unaff_BP;
    DAT_1262_021a = pcVar18;
    for (iVar9 = 0x5e; iVar9 != 0; iVar9 = iVar9 + -1) {
      puVar4 = puVar19;
      puVar19 = puVar19 + 1;
      *puVar4 = 0;
    }
    if (DAT_1262_0206 == 0) {
      DAT_1262_0206 = 0x585;
      DAT_1262_0208 = 0x1000;
      DAT_1262_020a = 0x585;
      DAT_1262_020c = 0x1000;
      DAT_1262_020e = 0x585;
      DAT_1262_0210 = 0x1000;
    }
    uVar21 = 1;
    DAT_1262_0212 = 0x584;
    DAT_1262_0214 = 0x1000;
    *(undefined2 *)(puVar12 + -2) = 0x528;
    FUN_1000_0981();
    puVar13 = (undefined2 *)(puVar12 + -2);
    *(undefined2 *)(puVar12 + -2) = 0x52b;
    uVar11 = FUN_1000_0920();
    *(undefined2 *)((int)puVar13 + -2) = uVar11;
    piVar20 = (int *)0x0;
    iVar9 = 0x10;
    do {
      if (iVar9 == 0) break;
      iVar9 = iVar9 + -1;
      piVar5 = piVar20;
      piVar20 = piVar20 + 1;
      uVar21 = *piVar5 == 0x101;
    } while ((bool)uVar21);
    uVar11 = *(undefined2 *)((int)puVar13 + -2);
    if ((bool)uVar21) goto LAB_1000_0573;
    DAT_1262_04a8 = 0x3a1;
  }
  puVar14 = (undefined2 *)0x4a6;
  DAT_1262_04a6 = 0x1000;
  pcVar7 = (code *)swi(0x21);
  DAT_1262_04aa = uVar11;
  (*pcVar7)();
  pcVar10 = (char *)puVar14[1];
  puVar15 = puVar14 + 2;
  do {
    pcVar2 = pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (*pcVar2 != '\0');
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
  uVar11 = *puVar15;
  puVar13 = puVar15 + 1;
LAB_1000_0573:
  *(undefined2 *)((int)puVar13 + -2) = uVar11;
  *(undefined2 *)((int)puVar13 + -4) = 0x577;
  FUN_1000_099c();
  pcVar7 = (code *)swi(0x21);
  uVar11 = (*pcVar7)();
  *(undefined2 *)((int)puVar13 + -2) = uVar11;
  return *(undefined2 *)((int)puVar13 + -2);
}



// WARNING: Unable to track spacebase fully for stack
// WARNING: This function may have set the stack pointer

undefined2 FUN_1000_03dc(void)

{
  uint *puVar1;
  char *pcVar2;
  char *pcVar3;
  undefined *puVar4;
  int *piVar5;
  char cVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  undefined2 uVar11;
  undefined *puVar12;
  undefined2 *puVar13;
  undefined2 *puVar14;
  undefined2 *puVar15;
  int unaff_BP;
  uint *puVar16;
  uint *puVar17;
  char *pcVar18;
  undefined *puVar19;
  int *piVar20;
  int unaff_DS;
  undefined uVar21;
  
  DAT_1262_01fc = (char *)0x430;
  puVar12 = &stack0x0430;
  uVar9 = (uint)&stack0x043f >> 4;
  uVar21 = DAT_1262_01fa == '\0';
  DAT_1262_01f6 = unaff_DS;
  DAT_1262_01fe = puVar12;
  if ((bool)uVar21) {
    if (uVar9 < *(int *)0x2 + 0xed9eU) {
      DAT_1262_01f4 = puVar12;
      if (uVar9 == 0) {
        DAT_1262_01f4 = (undefined *)0xfffe;
      }
      uVar21 = uVar9 + 0x1262 == unaff_DS;
      pcVar7 = (code *)swi(0x21);
      (*pcVar7)();
      goto LAB_1000_0455;
    }
    uVar11 = 1;
    DAT_1262_04a8 = 0x3c2;
  }
  else {
LAB_1000_0455:
    pcVar10 = (char *)0x81;
    uVar9 = (uint)*(byte *)0x80;
    do {
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      pcVar2 = pcVar10;
      pcVar10 = pcVar10 + 1;
      uVar21 = *pcVar2 == ' ';
    } while ((bool)uVar21);
    pcVar10 = pcVar10 + -1;
    DAT_1262_0216 = DAT_1262_01fc;
    DAT_1262_0218 = 0x1262;
    pcVar18 = DAT_1262_01fc;
    if (!(bool)uVar21) {
      for (iVar8 = uVar9 + 1; iVar8 != 0; iVar8 = iVar8 + -1) {
        pcVar3 = pcVar18;
        pcVar18 = pcVar18 + 1;
        pcVar2 = pcVar10;
        pcVar10 = pcVar10 + 1;
        *pcVar3 = *pcVar2;
      }
    }
    *pcVar18 = '\0';
    pcVar18[1] = '\0';
    pcVar18 = pcVar18 + 1;
    pcVar7 = (code *)swi(0x21);
    uVar11 = (*pcVar7)();
    DAT_1262_01f8 = (byte)uVar11;
    DAT_1262_01f9 = (undefined)((uint)uVar11 >> 8);
    DAT_1262_01fc = pcVar18;
    if (2 < DAT_1262_01f8) {
      uVar11 = *(undefined2 *)0x2c;
      puVar16 = (uint *)0x0;
      unaff_BP = 0;
      do {
        if (((*puVar16 | 0x2020) == 0x6f6e) && (puVar16[1] == 0x3738)) {
          unaff_BP = unaff_BP + 1;
        }
        do {
          puVar17 = puVar16;
          puVar16 = (uint *)((int)puVar17 + 1);
        } while (*(char *)puVar17 != '\0');
      } while (*(char *)puVar16 != '\0');
      puVar17 = puVar17 + 2;
      do {
        cVar6 = *(char *)puVar17;
        pcVar2 = DAT_1262_01fc;
        DAT_1262_01fc = DAT_1262_01fc + 1;
        puVar1 = puVar17;
        puVar17 = (uint *)((int)puVar17 + 1);
        *pcVar2 = *(char *)puVar1;
      } while (cVar6 != '\0');
    }
    DAT_1262_021c = 0x1262;
    puVar19 = (undefined *)0x3ce;
    DAT_1262_0204 = unaff_BP;
    DAT_1262_021a = pcVar18;
    for (iVar8 = 0x5e; iVar8 != 0; iVar8 = iVar8 + -1) {
      puVar4 = puVar19;
      puVar19 = puVar19 + 1;
      *puVar4 = 0;
    }
    if (DAT_1262_0206 == 0) {
      DAT_1262_0206 = 0x585;
      DAT_1262_0208 = 0x1000;
      DAT_1262_020a = 0x585;
      DAT_1262_020c = 0x1000;
      DAT_1262_020e = 0x585;
      DAT_1262_0210 = 0x1000;
    }
    uVar21 = 1;
    DAT_1262_0212 = 0x584;
    DAT_1262_0214 = 0x1000;
    *(undefined2 *)(puVar12 + -2) = 0x528;
    FUN_1000_0981();
    puVar13 = (undefined2 *)(puVar12 + -2);
    *(undefined2 *)(puVar12 + -2) = 0x52b;
    uVar11 = FUN_1000_0920();
    *(undefined2 *)((int)puVar13 + -2) = uVar11;
    piVar20 = (int *)0x0;
    iVar8 = 0x10;
    do {
      if (iVar8 == 0) break;
      iVar8 = iVar8 + -1;
      piVar5 = piVar20;
      piVar20 = piVar20 + 1;
      uVar21 = *piVar5 == 0x101;
    } while ((bool)uVar21);
    uVar11 = *(undefined2 *)((int)puVar13 + -2);
    if ((bool)uVar21) goto LAB_1000_0573;
    DAT_1262_04a8 = 0x3a1;
  }
  puVar14 = (undefined2 *)0x4a6;
  DAT_1262_04a6 = 0x1000;
  pcVar7 = (code *)swi(0x21);
  DAT_1262_04aa = uVar11;
  (*pcVar7)();
  pcVar10 = (char *)puVar14[1];
  puVar15 = puVar14 + 2;
  do {
    pcVar2 = pcVar10;
    pcVar10 = pcVar10 + 1;
  } while (*pcVar2 != '\0');
  pcVar7 = (code *)swi(0x21);
  (*pcVar7)();
  uVar11 = *puVar15;
  puVar13 = puVar15 + 1;
LAB_1000_0573:
  *(undefined2 *)((int)puVar13 + -2) = uVar11;
  *(undefined2 *)((int)puVar13 + -4) = 0x577;
  FUN_1000_099c();
  pcVar7 = (code *)swi(0x21);
  uVar11 = (*pcVar7)();
  *(undefined2 *)((int)puVar13 + -2) = uVar11;
  return *(undefined2 *)((int)puVar13 + -2);
}



undefined2 /*__cdecl16near*/ FUN_1000_057c(void)

{
  undefined2 in_AX;
  
  return in_AX;
}



int /*__cdecl16near*/ FUN_1000_0586(void)

{
  char *pcVar1;
  char *in_AX;
  uint uVar2;
  undefined2 unaff_DS;
  
  uVar2 = 0xffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar1 = in_AX;
    in_AX = in_AX + 1;
  } while (*pcVar1 != '\0');
  return ~uVar2 - 1;
}



int /*__cdecl16near*/ FUN_1000_059f(void)

{
  byte bVar1;
  byte *in_AX;
  byte bVar2;
  byte *in_DX;
  int in_BX;
  undefined2 unaff_DS;
  
  while( true ) {
    if (in_BX == 0) {
      return 0;
    }
    bVar1 = *in_AX;
    bVar2 = *in_DX;
    if ((0x40 < bVar1) && (bVar1 < 0x5b)) {
      bVar1 = bVar1 + 0x20;
    }
    if ((0x40 < bVar2) && (bVar2 < 0x5b)) {
      bVar2 = bVar2 + 0x20;
    }
    if (bVar1 != bVar2) break;
    if (bVar2 == 0) {
      return 0;
    }
    in_BX = in_BX + -1;
    in_DX = in_DX + 1;
    in_AX = in_AX + 1;
  }
  return (uint)bVar1 - (uint)bVar2;
}



// WARNING: Instruction at (ram,0x00010613) overlaps instruction at (ram,0x00010611)
// 

undefined2 /*__cdecl16near*/ FUN_1000_05ea(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  char cVar3;
  undefined2 *in_AX;
  char in_DL;
  undefined2 unaff_DS;
  
  while( true ) {
    puVar1 = in_AX + 1;
    uVar2 = *in_AX;
    cVar3 = (char)uVar2;
    if ((((cVar3 == in_DL) || (cVar3 == '\0')) || (cVar3 = (char)((uint)uVar2 >> 8), cVar3 == in_DL)
        ) || (cVar3 == '\0')) {
      return 0;
    }
    in_AX = in_AX + 2;
    uVar2 = *puVar1;
    cVar3 = (char)uVar2;
    if (cVar3 == in_DL) {
      return 0;
    }
    if (cVar3 == '\0') break;
    cVar3 = (char)((uint)uVar2 >> 8);
    if (cVar3 == in_DL) {
      return 0;
    }
    if (cVar3 == '\0') {
      return 0;
    }
  }
  return 0;
}



// WARNING: Instruction at (ram,0x0001062d) overlaps instruction at (ram,0x0001062c)
// 

char * /*__cdecl16near*/ FUN_1000_0618(void)

{
  char *pcVar1;
  char *in_AX;
  char in_DL;
  char *in_BX;
  undefined2 unaff_DS;
  undefined in_ZF;
  
  if (in_BX != (char *)0x0) {
    do {
      if (in_BX == (char *)0x0) break;
      in_BX = in_BX + -1;
      pcVar1 = in_AX;
      in_AX = in_AX + 1;
      in_ZF = in_DL == *pcVar1;
    } while (!(bool)in_ZF);
    if ((bool)in_ZF) goto code_r0x0001062b;
  }
  in_AX = in_BX;
code_r0x0001062b:
  return in_AX + -1;
}



void /*__cdecl16near*/ FUN_1000_0635(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  FUN_1000_0be6();
  return;
}



undefined2 /*__cdecl16near*/ FUN_1000_0658(void)

{
  code *pcVar1;
  int in_AX;
  undefined2 *puVar2;
  int iVar3;
  undefined2 uVar4;
  undefined2 unaff_DS;
  byte bVar5;
  
  bVar5 = 0;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if ((int)-(uint)bVar5 < 0) {
    puVar2 = (undefined2 *)FUN_1000_02d1();
    *puVar2 = 1;
  }
  else {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    FUN_1000_0586();
    if ((in_AX != 0) || (iVar3 = FUN_1000_0c61(), iVar3 != 0)) {
      uVar4 = FUN_1000_0cb4();
      return uVar4;
    }
    puVar2 = (undefined2 *)FUN_1000_02d1();
    *puVar2 = 5;
  }
  return 0;
}



undefined2 * /*__cdecl16near*/ FUN_1000_06cf(void)

{
  undefined2 *puVar1;
  char cVar2;
  undefined2 *in_AX;
  undefined2 uVar3;
  undefined2 *in_DX;
  undefined2 *puVar4;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  bool bVar6;
  
  puVar4 = in_AX;
  if (((uint)in_DX & 1) != 0) {
    puVar1 = in_DX;
    in_DX = (undefined2 *)((int)in_DX + 1);
    cVar2 = *(char *)puVar1;
    *(char *)in_AX = cVar2;
    puVar4 = (undefined2 *)((int)in_AX + 1);
    if (cVar2 == '\0') {
      return in_AX;
    }
  }
  do {
    uVar3 = *in_DX;
    puVar5 = puVar4;
    if ((char)uVar3 == '\0') goto LAB_1000_0708;
    *puVar4 = uVar3;
    if ((char)((uint)uVar3 >> 8) == '\0') {
      return in_AX;
    }
    uVar3 = in_DX[1];
    puVar5 = puVar4 + 1;
    if ((char)uVar3 == '\0') goto LAB_1000_0708;
    puVar4[1] = uVar3;
    in_DX = in_DX + 2;
    puVar4 = puVar4 + 2;
    bVar6 = (char)((uint)uVar3 >> 8) != '\0';
  } while (bVar6);
  puVar5 = puVar4;
  if (bVar6) {
LAB_1000_0708:
    *(char *)puVar5 = (char)uVar3;
  }
  return in_AX;
}



// WARNING: Instruction at (ram,0x00010738) overlaps instruction at (ram,0x00010737)
// 

char * /*__cdecl16near*/ FUN_1000_070e(void)

{
  undefined2 *puVar1;
  char *pcVar2;
  char *in_AX;
  undefined2 uVar3;
  int iVar4;
  undefined2 *in_DX;
  char *pcVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined2 unaff_DS;
  
  iVar4 = -1;
  pcVar5 = in_AX;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    pcVar2 = pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (*pcVar2 != '\0');
  puVar6 = (undefined2 *)(pcVar5 + -1);
  while( true ) {
    puVar1 = in_DX + 1;
    uVar3 = *in_DX;
    puVar7 = puVar6;
    if ((char)uVar3 == '\0') break;
    puVar7 = puVar6 + 1;
    *puVar6 = uVar3;
    if ((char)((uint)uVar3 >> 8) == '\0') {
      return in_AX;
    }
    in_DX = in_DX + 2;
    uVar3 = *puVar1;
    if ((char)uVar3 == '\0') break;
    puVar6 = puVar6 + 2;
    *puVar7 = uVar3;
    if ((char)((uint)uVar3 >> 8) == '\0') {
      return in_AX;
    }
  }
  *(char *)puVar7 = (char)uVar3;
  return in_AX;
}



int /*__cdecl16near*/ FUN_1000_0741(void)

{
  char *in_AX;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined2 unaff_DS;
  undefined4 uVar6;
  undefined2 uStack_a2;
  undefined local_a0 [146];
  int local_e;
  uint local_c;
  uint local_a;
  
  uStack_a2 = 0x759;
  iVar1 = FUN_1000_0cdd();
  iVar4 = iVar1;
  if (iVar1 == -1) {
    uStack_a2 = 0x765;
    uVar6 = FUN_1000_02d1();
    iVar4 = (int)((ulong)uVar6 >> 0x10);
    if ((((*(int *)uVar6 == 1) && (*in_AX != '\\')) && (*in_AX != '\0')) && (in_AX[1] != ':')) {
      uStack_a2 = 0x782;
      pcVar2 = (char *)FUN_1000_00b5();
      iVar4 = iVar1;
      if (pcVar2 != (char *)0x0) {
        uStack_a2 = 0x795;
        uVar6 = FUN_1000_0586();
        iVar4 = (int)((ulong)uVar6 >> 0x10);
        local_e = (int)uVar6 + 1;
        local_a = 0x90 - local_e;
        while (*pcVar2 != '\0') {
          uStack_a2 = 0x7af;
          pcVar3 = (char *)FUN_1000_05ea();
          if (pcVar3 == (char *)0x0) {
            uStack_a2 = 0x7ba;
            iVar4 = FUN_1000_0586();
            pcVar3 = pcVar2 + iVar4;
          }
          local_c = (int)pcVar3 - (int)pcVar2;
          if (local_a < local_c) {
            uStack_a2 = 0x7cd;
            puVar5 = (undefined2 *)FUN_1000_02d1();
            *puVar5 = 2;
            uStack_a2 = 0x7d6;
            puVar5 = (undefined2 *)FUN_1000_02d5();
            *puVar5 = 10;
            return -1;
          }
          uStack_a2 = 0x7ec;
          FUN_1000_10ce();
          if (local_a0[local_c - 1] != '\\') {
            local_a0[local_c] = 0x5c;
          }
          uStack_a2 = 0x806;
          FUN_1000_10ce();
          uStack_a2 = 0x811;
          iVar4 = FUN_1000_0cdd();
          if (iVar4 != -1) {
            return iVar4;
          }
          uStack_a2 = 0x81b;
          uVar6 = FUN_1000_02d1();
          iVar4 = (int)((ulong)uVar6 >> 0x10);
          if (*(int *)uVar6 != 1) {
            return iVar4;
          }
          if (*pcVar3 != ';') {
            return iVar4;
          }
          pcVar2 = pcVar3 + 1;
        }
      }
    }
  }
  return iVar4;
}



int /*__cdecl16near*/ FUN_1000_0838(void)

{
  byte *pbVar1;
  char *pcVar2;
  char *in_AX;
  int iVar3;
  int iVar4;
  int in_DX;
  undefined2 unaff_DS;
  bool bVar5;
  
  if (*(int *)(in_DX + 4) == 0) {
    FUN_1000_10ed();
  }
  bVar5 = (*(byte *)(in_DX + 7) & 4) != 0;
  if (bVar5) {
    pbVar1 = (byte *)(in_DX + 7);
    *pbVar1 = *pbVar1 & 0xfb;
    pbVar1 = (byte *)(in_DX + 7);
    *pbVar1 = *pbVar1 | 2;
  }
  iVar4 = 0;
  do {
    pcVar2 = in_AX;
    in_AX = in_AX + 1;
    iVar3 = iVar4;
    if (*pcVar2 == '\0') break;
    iVar3 = FUN_1000_0893();
  } while (iVar3 != -1);
  if (bVar5) {
    pbVar1 = (byte *)(in_DX + 7);
    *pbVar1 = *pbVar1 & 0xfd;
    pbVar1 = (byte *)(in_DX + 7);
    *pbVar1 = *pbVar1 | 4;
    if (iVar3 == 0) {
      iVar3 = FUN_1000_114a();
    }
  }
  return iVar3;
}



uint /*__cdecl16near*/ FUN_1000_0893(void)

{
  byte **ppbVar1;
  byte *pbVar2;
  int in_AX;
  undefined2 *puVar3;
  int iVar4;
  byte bVar5;
  byte **in_DX;
  uint uVar6;
  undefined2 unaff_DS;
  
  if ((*(byte *)(in_DX + 3) & 2) == 0) {
    puVar3 = (undefined2 *)FUN_1000_02d1();
    *puVar3 = 4;
    ppbVar1 = in_DX + 3;
    *(byte *)ppbVar1 = *(byte *)ppbVar1 | 0x20;
    return 0xffff;
  }
  if (in_DX[2] == (byte *)0x0) {
    FUN_1000_10ed();
  }
  uVar6 = 0x400;
  if ((in_AX == 10) && (uVar6 = 0x600, (*(byte *)(in_DX + 3) & 0x40) == 0)) {
    pbVar2 = (byte *)((int)in_DX + 7);
    *pbVar2 = *pbVar2 | 0x10;
    **in_DX = 0xd;
    ppbVar1 = in_DX;
    *ppbVar1 = *ppbVar1 + 1;
    ppbVar1 = in_DX + 1;
    *ppbVar1 = *ppbVar1 + 1;
    if ((in_DX[1] == in_DX[5]) && (iVar4 = FUN_1000_114a(), iVar4 != 0)) {
      return 0xffff;
    }
  }
  pbVar2 = (byte *)((int)in_DX + 7);
  *pbVar2 = *pbVar2 | 0x10;
  bVar5 = (byte)in_AX;
  **in_DX = bVar5;
  ppbVar1 = in_DX;
  *ppbVar1 = *ppbVar1 + 1;
  ppbVar1 = in_DX + 1;
  *ppbVar1 = *ppbVar1 + 1;
  if (((((uint)in_DX[3] & uVar6) != 0) || (in_DX[1] == in_DX[5])) &&
     (iVar4 = FUN_1000_114a(), iVar4 != 0)) {
    return 0xffff;
  }
  return (uint)bVar5;
}



void FUN_1000_0920(void)

{
  undefined2 unaff_DS;
  
  *(undefined2 *)0x36a = 0x2000;
  FUN_1000_0066();
  FUN_1000_02f3();
  return;
}



uint /*__cdecl16near*/ FUN_1000_0934(void)

{
  byte *pbVar1;
  code **ppcVar2;
  uint uVar3;
  code *in_CX;
  byte extraout_DL;
  byte extraout_DL_00;
  byte extraout_DL_01;
  byte extraout_DL_02;
  byte bVar4;
  byte *pbVar5;
  byte *unaff_SI;
  byte *pbVar6;
  byte *unaff_DI;
  undefined2 unaff_DS;
  bool bVar7;
  bool bVar8;
  
  uVar3 = FUN_1000_057c();
  bVar4 = extraout_DL;
  while( true ) {
    uVar3 = uVar3 & 0xff00 | (uint)bVar4;
    pbVar5 = unaff_DI;
    for (pbVar6 = unaff_SI; pbVar6 < unaff_DI; pbVar6 = pbVar6 + 6) {
      pbVar1 = pbVar6;
      bVar7 = *pbVar1 < 2;
      bVar8 = *pbVar1 == 2;
      if ((!bVar8) && (uVar3 = (*in_CX)(), bVar4 = extraout_DL_00, bVar7 || bVar8)) {
        uVar3 = uVar3 & 0xff00 | (uint)pbVar6[1];
        pbVar5 = pbVar6;
      }
    }
    if (pbVar5 == unaff_DI) break;
    uVar3 = *(uint *)(pbVar5 + 2);
    if (*pbVar5 == 1) {
      uVar3 = uVar3 | *(uint *)(pbVar5 + 4);
      if (uVar3 != 0) {
        ppcVar2 = (code **)(pbVar5 + 2);
        uVar3 = (**ppcVar2)(0x1000);
        bVar4 = extraout_DL_01;
      }
    }
    else if (uVar3 != 0) {
      uVar3 = (**(code **)(pbVar5 + 2))();
      bVar4 = extraout_DL_02;
    }
    *pbVar5 = 2;
  }
  return uVar3;
}



void /*__cdecl16near*/ FUN_1000_0981(void)

{
  FUN_1000_0934();
  return;
}



void /*__cdecl16near*/ FUN_1000_099c(void)

{
  FUN_1000_0934();
  return;
}



void /*__cdecl16near*/ FUN_1000_09bd(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 unaff_DS;
  int local_c;
  
  iVar2 = FUN_1000_0a41();
  iVar2 = iVar2 + 1;
  iVar4 = (local_c - *(int *)0x216) + 1;
  iVar3 = FUN_1000_0c61();
  if (iVar3 == 0) {
    *(undefined2 *)0x1ec = 0;
    *(undefined2 *)0x1ea = 0;
  }
  else {
    *(int *)0x1ec = iVar3 + iVar4;
    FUN_1000_10ce();
    **(undefined2 **)0x1ec = *(undefined2 *)0x21a;
    FUN_1000_0a41();
    *(undefined2 *)(iVar2 * 2 + *(int *)0x1ec) = 0;
    *(int *)0x1ea = iVar2;
  }
  uVar1 = *(undefined2 *)0x1ec;
  *(int *)0x428 = iVar2;
  *(undefined2 *)0x426 = uVar1;
  return;
}



int /*__cdecl16near*/ FUN_1000_0a41(void)

{
  char *in_AX;
  int iVar1;
  int in_DX;
  char **in_BX;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined2 unaff_DS;
  char *local_e;
  int local_c;
  
  local_c = 0;
  do {
    while( true ) {
      for (; (*in_AX == ' ' || (*in_AX == '\t')); in_AX = in_AX + 1) {
      }
      pcVar4 = in_AX;
      if (*in_AX == '\0') goto LAB_1000_0b18;
      pcVar2 = in_AX;
      if (*in_AX == '\"') {
        local_e = in_AX + 1;
        pcVar2 = local_e;
        pcVar4 = local_e;
        while ((*pcVar4 != '\"' && (*pcVar4 != '\0'))) {
          pcVar3 = pcVar4;
          if ((*pcVar4 == '\\') && ((pcVar4[1] == '\"' || (pcVar4[1] == '\\')))) {
            pcVar3 = pcVar4 + 1;
          }
          pcVar4 = pcVar3 + 1;
          if (in_DX != 0) {
            *pcVar2 = *pcVar3;
            pcVar2 = pcVar2 + 1;
          }
        }
      }
      else {
        while (((local_e = in_AX, *pcVar4 != '\0' && (*pcVar4 != ' ')) && (*pcVar4 != '\t'))) {
          pcVar3 = pcVar4;
          if ((*pcVar4 == '\\') && (pcVar4[1] == '\"')) {
            pcVar3 = pcVar4 + 1;
          }
          pcVar4 = pcVar3 + 1;
          if (in_DX != 0) {
            *pcVar2 = *pcVar3;
            pcVar2 = pcVar2 + 1;
          }
        }
      }
      in_AX = pcVar4 + 1;
      iVar1 = local_c + 1;
      if (in_DX != 0) break;
      local_c = iVar1;
      if (*pcVar4 == '\0') {
LAB_1000_0b18:
        *in_BX = pcVar4;
        return local_c;
      }
    }
    *(char **)(local_c * 2 + in_DX) = local_e;
    if (*pcVar4 == '\0') {
      *pcVar2 = '\0';
      local_c = iVar1;
      goto LAB_1000_0b18;
    }
    *pcVar2 = '\0';
    local_c = iVar1;
  } while( true );
}



ulong /*__cdecl16near*/ FUN_1000_0be6(void)

{
  uint in_AX;
  uint *puVar1;
  uint uVar2;
  byte extraout_DL;
  byte bVar3;
  int in_DX;
  byte bVar4;
  undefined2 unaff_DS;
  
  if (in_DX == 0) {
    return 0;
  }
  if (in_DX != 0) {
    uVar2 = in_AX & 0xff;
    puVar1 = (uint *)FUN_1000_02d5();
    *puVar1 = uVar2;
    uVar2 = in_AX >> 8;
    if (in_AX < 0x100) {
      bVar3 = extraout_DL;
      if (2 < *(byte *)0x1f8) {
        bVar4 = (byte)in_AX;
        if (bVar4 == 0x50) {
          bVar3 = 0xe;
        }
        else if (bVar4 < 0x22) {
          if (0x1f < bVar4) {
            bVar3 = 5;
          }
        }
        else {
          bVar3 = 0x13;
        }
      }
      if (0x13 < bVar3) {
        bVar3 = 0x13;
      }
      uVar2 = (uint)*(char *)(bVar3 + 0x33c);
    }
    puVar1 = (uint *)FUN_1000_02d1();
    *puVar1 = uVar2;
    return CONCAT22(in_DX,0xffff);
  }
  return (ulong)in_AX;
}



undefined4 /*__cdecl16near*/ FUN_1000_0c01(void)

{
  uint in_AX;
  uint *puVar1;
  uint uVar2;
  byte extraout_DL;
  byte bVar3;
  undefined2 in_DX;
  byte bVar4;
  undefined2 unaff_DS;
  
  uVar2 = in_AX & 0xff;
  puVar1 = (uint *)FUN_1000_02d5();
  *puVar1 = uVar2;
  uVar2 = in_AX >> 8;
  if (in_AX < 0x100) {
    bVar3 = extraout_DL;
    if (2 < *(byte *)0x1f8) {
      bVar4 = (byte)in_AX;
      if (bVar4 == 0x50) {
        bVar3 = 0xe;
      }
      else if (bVar4 < 0x22) {
        if (0x1f < bVar4) {
          bVar3 = 5;
        }
      }
      else {
        bVar3 = 0x13;
      }
    }
    if (0x13 < bVar3) {
      bVar3 = 0x13;
    }
    uVar2 = (uint)*(char *)(bVar3 + 0x33c);
  }
  puVar1 = (uint *)FUN_1000_02d1();
  *puVar1 = uVar2;
  return CONCAT22(in_DX,0xffff);
}



void /*__cdecl16near*/ FUN_1000_0c61(void)

{
  bool bVar1;
  int in_AX;
  int iVar2;
  undefined2 unaff_DS;
  
  if (in_AX != 0) {
    do {
      bVar1 = false;
      while( true ) {
        iVar2 = FUN_1000_1212();
        if (iVar2 != 0) goto LAB_1000_0ca5;
        if ((bVar1) || (iVar2 = FUN_1000_144c(), iVar2 == 0)) break;
        bVar1 = true;
      }
      iVar2 = FUN_1000_1520();
    } while (iVar2 != 0);
LAB_1000_0ca5:
    *(undefined *)0x42a = 0;
  }
  return;
}



void /*__cdecl16near*/ FUN_1000_0cb4(void)

{
  char *pcVar1;
  char cVar2;
  undefined2 *puVar3;
  undefined2 *in_AX;
  uint uVar4;
  char *in_DX;
  uint in_BX;
  undefined2 unaff_DS;
  
  if (in_BX != 0) {
    do {
      pcVar1 = in_DX;
      in_DX = in_DX + 1;
      cVar2 = *pcVar1;
      puVar3 = in_AX;
      in_AX = (undefined2 *)((int)in_AX + 1);
      *(char *)puVar3 = cVar2;
      in_BX = in_BX - 1;
    } while (in_BX != 0 && cVar2 != '\0');
    for (uVar4 = in_BX >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
      puVar3 = in_AX;
      in_AX = in_AX + 1;
      *puVar3 = 0;
    }
    for (uVar4 = (uint)((in_BX & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
      puVar3 = in_AX;
      in_AX = (undefined2 *)((int)in_AX + 1);
      *(undefined *)puVar3 = 0;
    }
  }
  return;
}



undefined2 /*__cdecl16near*/ FUN_1000_0cdd(void)

{
  undefined2 in_AX;
  int iVar1;
  undefined2 *puVar2;
  int *extraout_DX;
  undefined2 in_BX;
  undefined2 unaff_DS;
  undefined4 uVar3;
  int *piVar4;
  undefined local_100 [128];
  undefined local_80 [80];
  int local_30;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined local_14 [6];
  undefined local_e [2];
  int local_c;
  
  FUN_1000_1529();
  piVar4 = extraout_DX;
  FUN_1000_0cb4(in_BX,extraout_DX,in_AX);
  FUN_1000_155d();
  iVar1 = FUN_1000_05ea();
  if (iVar1 == 0) {
    FUN_1000_070e();
    iVar1 = FUN_1000_1581(local_80,0x200,0);
    if (iVar1 != -1) goto LAB_1000_0d74;
    puVar2 = (undefined2 *)FUN_1000_155d();
    *puVar2 = *(undefined2 *)0x19d;
    puVar2[1] = *(undefined2 *)0x19f;
    *(undefined *)(puVar2 + 2) = *(undefined *)0x1a1;
  }
  FUN_1000_1581(local_80,0x200,0);
  uVar3 = FUN_1000_02d1();
  *(undefined2 *)uVar3 = 1;
  if ((int)((ulong)uVar3 >> 0x10) == -1) {
    return 0xffff;
  }
LAB_1000_0d74:
  iVar1 = FUN_1000_175e();
  if (iVar1 == -1) {
    FUN_1000_183e();
    puVar2 = (undefined2 *)FUN_1000_02d1();
    *puVar2 = 3;
    puVar2 = (undefined2 *)FUN_1000_02d5();
    *puVar2 = 0xb;
  }
  else {
    if ((local_30 == 0x5a4d) || (local_30 == 0x4d5a)) {
      local_c = 1;
    }
    else {
      local_c = 0;
    }
    if (local_c == 0) {
      FUN_1000_186c();
      FUN_1000_18ac();
    }
    FUN_1000_183e();
    *piVar4 = (int)local_80;
    iVar1 = FUN_1000_199e(local_e,local_14,1);
    if (iVar1 != -1) {
      FUN_1000_0586();
      FUN_1000_1acc();
      iVar1 = FUN_1000_0f56();
      if (iVar1 != 0) {
        FUN_1000_1c5d(0x1000,local_80,local_100,local_c,local_22,local_20,local_1a,local_1c);
      }
      FUN_1000_1200();
    }
  }
  return 0xffff;
}



undefined4 /*__cdecl16near*/ FUN_1000_0e8e(void)

{
  undefined2 extraout_DX;
  int local_1e;
  undefined2 local_12;
  
  FUN_1000_1529();
  FUN_1000_1d61();
  return CONCAT22(extraout_DX,*(int *)(local_1e + -2) + 1);
}



void /*__cdecl16near*/ FUN_1000_0ecd(void)

{
  code *pcVar1;
  undefined2 extraout_DX;
  undefined2 in_BX;
  
  FUN_1000_1529();
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(extraout_DX,in_BX);
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return;
}



undefined4 /*__cdecl16near*/ FUN_1000_0eef(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 in_CX;
  undefined2 in_BX;
  byte in_CF;
  
  FUN_1000_1529();
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)(in_CX);
  if ((int)-(uint)in_CF < 0) {
    uVar2 = 0;
  }
  else {
    FUN_1000_0ecd();
  }
  return CONCAT22(in_BX,uVar2);
}



undefined2 /*__cdecl16near*/ FUN_1000_0f15(void)

{
  code *pcVar1;
  int in_AX;
  undefined2 uVar2;
  undefined2 in_CX;
  int extraout_DX;
  undefined2 in_BX;
  
  FUN_1000_1529();
  if (*(uint *)0x3 < extraout_DX + 1U) {
    uVar2 = 0;
  }
  else {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)(in_CX,in_BX);
    uVar2 = FUN_1000_0eef();
  }
  return uVar2;
}



void /*__cdecl16near*/ FUN_1000_0f4b(void)

{
  undefined2 unaff_DS;
  
  FUN_1000_1529();
  (**(code **)0x1e6)();
  return;
}



undefined2 /*__cdecl16near*/ FUN_1000_0f56(void)

{
  uint uVar1;
  code *pcVar2;
  uint in_AX;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 extraout_DX;
  int iVar6;
  int in_BX;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined2 unaff_DS;
  undefined2 uVar10;
  
  FUN_1000_1529();
  uVar8 = 0;
  iVar9 = 0;
  iVar7 = 0;
  uVar10 = extraout_DX;
  uVar5 = in_AX;
  while (iVar3 = FUN_1000_0eef(in_BX,uVar10,in_AX,uVar5), iVar3 != 0) {
    *(int *)0x0 = iVar7;
    iVar7 = iVar3;
  }
  iVar3 = iVar7;
  if ((*(char *)0x1f8 != '\x02') ||
     ((iVar7 != 0 && (iVar9 = FUN_1000_0f15(), iVar3 = iVar7, iVar9 != 0)))) {
    while ((iVar3 != 0 && (uVar8 = FUN_1000_0f15(), uVar8 == 0))) {
      iVar3 = *(int *)0x0;
    }
    if (uVar8 != 0) {
      uVar5 = *(uint *)0x1f6;
      do {
        if (uVar8 <= uVar5) {
LAB_1000_0ff7:
          *(uint *)0x2c = uVar8;
          FUN_1000_1e02(in_BX << 4);
          FUN_1000_0f4b();
          do {
            for (uVar5 = FUN_1000_0e8e();
                ((uVar1 = *(uint *)0x1, uVar1 != *(uint *)0x1f6 || (uVar5 == uVar1)) ||
                (uVar5 == uVar8)); uVar5 = uVar5 + *(int *)0x3 + 1) {
              iVar7 = 0;
              if (*(char *)0x0 != 'M') {
                FUN_1000_0ecd();
                *(int *)(iVar7 + 2) = *(int *)0x1f6 + *(int *)(iVar7 + 3);
                if (*(uint *)(iVar7 + 3) < in_AX) {
                  FUN_1000_02b3();
                  pcVar2 = (code *)swi(0x21);
                  (*pcVar2)();
                }
                return 1;
              }
            }
            pcVar2 = (code *)swi(0x21);
            (*pcVar2)();
          } while( true );
        }
        iVar6 = uVar5 - 1;
        iVar3 = *(int *)0x1;
        if (iVar3 != *(int *)0x1f6) goto LAB_1000_0ff7;
        iVar4 = uVar5 + *(int *)0x3;
        if (*(char *)0x0 != 'M') {
          if ((uint)(iVar4 - iVar3) < in_AX) break;
          goto LAB_1000_0ff7;
        }
        uVar5 = iVar4 + 1;
      } while( true );
    }
  }
  if (iVar9 != 0) {
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)();
  }
  if (uVar8 != 0) {
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)();
  }
  while (iVar7 != 0) {
    iVar7 = *(int *)0x0;
    pcVar2 = (code *)swi(0x21);
    (*pcVar2)();
  }
  return 0;
}



undefined2 * /*__cdecl16near*/ FUN_1000_10ce(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 *in_AX;
  uint uVar3;
  undefined2 *in_DX;
  uint in_BX;
  undefined2 *puVar4;
  undefined2 unaff_DS;
  
  puVar4 = in_AX;
  for (uVar3 = in_BX >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = puVar4;
    puVar4 = puVar4 + 1;
    puVar1 = in_DX;
    in_DX = in_DX + 1;
    *puVar2 = *puVar1;
  }
  for (uVar3 = (uint)((in_BX & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = puVar4;
    puVar4 = (undefined2 *)((int)puVar4 + 1);
    puVar1 = in_DX;
    in_DX = (undefined2 *)((int)in_DX + 1);
    *(undefined *)puVar2 = *(undefined *)puVar1;
  }
  return in_AX;
}



void /*__cdecl16near*/ FUN_1000_10ed(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  undefined2 *in_AX;
  int iVar3;
  undefined2 unaff_DS;
  
  FUN_1000_1eaf();
  if (in_AX[5] == 0) {
    if ((*(byte *)((int)in_AX + 7) & 2) == 0) {
      if ((*(byte *)((int)in_AX + 7) & 4) == 0) {
        in_AX[5] = 0x200;
      }
      else {
        in_AX[5] = 1;
      }
    }
    else {
      in_AX[5] = 0x86;
    }
  }
  iVar3 = FUN_1000_0c61();
  in_AX[2] = iVar3;
  if (iVar3 == 0) {
    pbVar1 = (byte *)((int)in_AX + 7);
    *pbVar1 = *pbVar1 & 0xf8;
    pbVar1 = (byte *)((int)in_AX + 7);
    *pbVar1 = *pbVar1 | 4;
    in_AX[2] = in_AX + 6;
    in_AX[5] = 1;
  }
  else {
    puVar2 = in_AX + 3;
    *(byte *)puVar2 = *(byte *)puVar2 | 8;
  }
  *in_AX = in_AX[2];
  in_AX[1] = 0;
  return;
}



undefined4 /*__cdecl16near*/ FUN_1000_114a(void)

{
  byte *pbVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined2 *in_AX;
  int iVar4;
  undefined2 *puVar5;
  undefined2 in_DX;
  int iVar6;
  undefined2 unaff_DS;
  long lVar7;
  
  iVar6 = 0;
  if ((*(byte *)((int)in_AX + 7) & 0x10) == 0) {
    if ((in_AX[2] == 0) ||
       (puVar2 = in_AX + 3, *(byte *)puVar2 = *(byte *)puVar2 & 0xef,
       (*(byte *)((int)in_AX + 7) & 0x20) != 0)) goto LAB_1000_11d1;
    uVar3 = in_AX[1];
    lVar7 = (long)(int)uVar3;
    if (((int)uVar3 >> 0xf | uVar3) != 0) {
      lVar7 = FUN_1000_186c();
    }
    if (lVar7 != -1) goto LAB_1000_11d1;
    iVar4 = -1;
  }
  else {
    pbVar1 = (byte *)((int)in_AX + 7);
    *pbVar1 = *pbVar1 & 0xef;
    if (((*(byte *)(in_AX + 3) & 2) == 0) || (in_AX[2] == 0)) goto LAB_1000_11d1;
    iVar4 = FUN_1000_1ed2();
    if (iVar4 != -1) {
      if (iVar4 == in_AX[1]) goto LAB_1000_11d1;
      puVar5 = (undefined2 *)FUN_1000_02d1();
      *puVar5 = 0xc;
      iVar4 = -1;
    }
  }
  puVar2 = in_AX + 3;
  *(byte *)puVar2 = *(byte *)puVar2 | 0x20;
  iVar6 = iVar4;
LAB_1000_11d1:
  *in_AX = in_AX[2];
  in_AX[1] = 0;
  return CONCAT22(in_DX,iVar6);
}



void /*__cdecl16near*/ FUN_1000_1200(void)

{
  undefined2 unaff_DS;
  
  FUN_1000_12b6();
  *(undefined *)0x42a = 0;
  return;
}



uint * /*__cdecl16near*/ FUN_1000_1212(void)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint in_AX;
  uint uVar4;
  undefined2 in_DX;
  int in_BX;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  
  if (((in_AX != 0) && (in_AX < 0xfffd)) &&
     (uVar4 = in_AX + 3 & 0xfffe, uVar4 = (uVar4 - 6 & -(uint)(5 < uVar4)) + 6,
     puVar1 = (uint *)(in_BX + 10), uVar4 < *puVar1 || uVar4 == *puVar1)) {
    puVar5 = *(uint **)(in_BX + 6);
    uVar6 = *(uint *)(in_BX + 8);
    if (uVar4 <= uVar6) {
      puVar5 = *(uint **)(in_BX + 0x14);
      uVar6 = 0;
    }
    do {
      uVar3 = *puVar5;
      if (uVar4 <= uVar3) {
        *(uint *)(in_BX + 8) = uVar6;
        piVar2 = (int *)(in_BX + 0xc);
        *piVar2 = *piVar2 + 1;
        uVar6 = puVar5[2];
        if (uVar3 - uVar4 < 6) {
          piVar2 = (int *)(in_BX + 0xe);
          *piVar2 = *piVar2 + -1;
          uVar4 = puVar5[1];
          *(uint *)(uVar4 + 4) = uVar6;
          *(uint *)(uVar6 + 2) = uVar4;
          *(uint *)(in_BX + 6) = uVar4;
        }
        else {
          puVar7 = (uint *)((int)puVar5 + uVar4);
          *(uint **)(in_BX + 6) = puVar7;
          *puVar7 = uVar3 - uVar4;
          *puVar5 = uVar4;
          uVar4 = puVar5[1];
          puVar7[1] = uVar4;
          puVar7[2] = uVar6;
          *(uint **)(uVar4 + 4) = puVar7;
          *(uint **)(uVar6 + 2) = puVar7;
        }
        puVar1 = puVar5;
        *puVar1 = *puVar1 | 1;
        return puVar5 + 1;
      }
      uVar6 = (uVar6 - uVar3 & -(uint)(uVar3 <= uVar6)) + uVar3;
      puVar5 = (uint *)puVar5[2];
    } while (puVar5 != (uint *)(in_BX + 0x10U));
    *(uint *)(in_BX + 10) = uVar6;
  }
  return (uint *)0x0;
}



void /*__cdecl16near*/ FUN_1000_12b6(void)

{
  int *piVar1;
  uint **ppuVar2;
  uint uVar3;
  uint **in_AX;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  undefined2 in_DX;
  int in_BX;
  uint **ppuVar7;
  uint **ppuVar8;
  uint *puVar9;
  uint **ppuVar10;
  
  if (in_AX == (uint **)0x0) {
    return;
  }
  ppuVar7 = in_AX + -1;
  puVar6 = *ppuVar7;
  if (((uint)puVar6 & 1) == 0) {
    return;
  }
  puVar6 = (uint *)((uint)puVar6 & 0xfffe);
  puVar9 = (uint *)((int)ppuVar7 + (int)puVar6);
  if ((*puVar9 & 1) == 0) {
    if (puVar9 == *(uint **)(in_BX + 6)) {
      *(undefined2 *)(in_BX + 6) = ppuVar7;
    }
    *ppuVar7 = (uint *)((int)puVar6 + *puVar9);
    puVar6 = (uint *)puVar9[1];
    ppuVar10 = (uint **)puVar9[2];
    puVar6[2] = (uint)ppuVar10;
    ppuVar10[1] = puVar6;
    piVar1 = (int *)(in_BX + 0xe);
    *piVar1 = *piVar1 + -1;
  }
  else {
    *ppuVar7 = puVar6;
    ppuVar10 = (uint **)*(uint **)(in_BX + 6);
    if (ppuVar7 < ppuVar10) {
      ppuVar2 = ppuVar10 + 1;
      if ((*ppuVar2 <= ppuVar7 && ppuVar7 != (uint **)*ppuVar2) ||
         (ppuVar10 = (uint **)*(uint **)(in_BX + 0x14), ppuVar7 < ppuVar10)) goto LAB_1000_1372;
    }
    else {
      ppuVar10 = (uint **)ppuVar10[2];
      if ((ppuVar7 < ppuVar10) ||
         (ppuVar10 = (uint **)(in_BX + 0x10), ppuVar2 = (uint **)(in_BX + 0x12),
         *ppuVar2 <= ppuVar7 && ppuVar7 != (uint **)*ppuVar2)) goto LAB_1000_1372;
    }
    uVar3 = *(uint *)(in_BX + 0xe);
    uVar4 = *(uint *)(in_BX + 0xc) / (uVar3 + 1);
    if (uVar4 < uVar3) {
      iVar5 = uVar4 * 2;
      if (*(int *)(in_BX + 0xc) - uVar3 <= uVar3) {
        iVar5 = 0;
      }
      ppuVar10 = (uint **)((int)ppuVar7 + (int)*ppuVar7);
      do {
        puVar6 = *ppuVar10;
        if (((uint)puVar6 & 1) == 0) goto LAB_1000_1372;
        if (puVar6 == (uint *)0xffff) break;
        ppuVar10 = (uint **)((int)ppuVar10 + ((uint)puVar6 & 0xfffe));
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    ppuVar10 = (uint **)*(uint **)(in_BX + 6);
    if (ppuVar7 < ppuVar10) {
      ppuVar10 = (uint **)*(uint **)(in_BX + 0x14);
    }
    while (((ppuVar10 <= ppuVar7 && (ppuVar10 = (uint **)ppuVar10[2], ppuVar10 <= ppuVar7)) &&
           (ppuVar10 = (uint **)ppuVar10[2], ppuVar10 <= ppuVar7))) {
      ppuVar10 = (uint **)ppuVar10[2];
    }
  }
LAB_1000_1372:
  ppuVar8 = (uint **)ppuVar10[1];
  puVar6 = *ppuVar7;
  if ((uint **)((int)ppuVar8 + (int)*ppuVar8) == ppuVar7) {
    puVar6 = (uint *)((int)puVar6 + (int)*ppuVar8);
    *ppuVar8 = puVar6;
    if (ppuVar7 == (uint **)*(undefined2 *)(in_BX + 6)) {
      *(uint **)(in_BX + 6) = (uint *)ppuVar8;
    }
  }
  else {
    piVar1 = (int *)(in_BX + 0xe);
    *piVar1 = *piVar1 + 1;
    in_AX[1] = (uint *)ppuVar10;
    *in_AX = (uint *)ppuVar8;
    ppuVar8[2] = (uint *)ppuVar7;
    ppuVar10[1] = (uint *)ppuVar7;
    ppuVar8 = ppuVar7;
  }
  piVar1 = (int *)(in_BX + 0xc);
  *piVar1 = *piVar1 + -1;
  if ((ppuVar8 < *(uint **)(in_BX + 6)) &&
     (ppuVar2 = (uint **)(in_BX + 8), *ppuVar2 <= puVar6 && puVar6 != *ppuVar2)) {
    *(uint **)(in_BX + 8) = puVar6;
  }
  ppuVar2 = (uint **)(in_BX + 10);
  if (*ppuVar2 <= puVar6 && puVar6 != *ppuVar2) {
    *(uint **)(in_BX + 10) = puVar6;
  }
  return;
}



uint * /*__cdecl16near*/ FUN_1000_13bf(void)

{
  uint **ppuVar1;
  uint *puVar2;
  int *piVar3;
  int *in_AX;
  int *piVar4;
  uint *puVar5;
  int *piVar6;
  uint uVar7;
  undefined2 unaff_DS;
  
  piVar3 = *(int **)0x352;
  piVar6 = (int *)0x0;
  while ((piVar4 = piVar3, piVar4 != (int *)0x0 && (piVar4 <= in_AX))) {
    piVar6 = piVar4;
    piVar3 = (int *)piVar4[2];
  }
  in_AX[1] = (int)piVar6;
  in_AX[2] = (int)piVar4;
  if (piVar6 == (int *)0x0) {
    *(int **)0x350 = in_AX;
    *(int **)0x352 = in_AX;
  }
  else {
    piVar6[2] = (int)in_AX;
    *(int **)((int)piVar6 + *piVar6 + 2) = in_AX + 3;
  }
  if (piVar4 != (int *)0x0) {
    piVar4[1] = (int)in_AX;
    piVar4 = piVar4 + 3;
  }
  puVar5 = (uint *)(in_AX + 3);
  uVar7 = *in_AX - 6;
  *puVar5 = uVar7;
  ppuVar1 = (uint **)0x35a;
  if ((puVar5 < *ppuVar1 || puVar5 == *ppuVar1) &&
     (puVar2 = (uint *)0x35c, *puVar2 <= uVar7 && uVar7 != *puVar2)) {
    *(uint *)0x35c = uVar7;
  }
  *(undefined2 *)(uVar7 + (int)puVar5) = 0xffff;
  ((undefined2 *)(uVar7 + (int)puVar5))[1] = piVar4;
  return puVar5;
}



int /*__cdecl16near*/ FUN_1000_142b(void)

{
  int *piVar1;
  int iVar2;
  undefined2 unaff_DS;
  
  if ((*(int *)0x350 == 0) || (piVar1 = *(int **)0x366, (int)piVar1 + *piVar1 + 4 != *(int *)0x1f4))
  {
    iVar2 = 0;
  }
  else {
    iVar2 = *piVar1;
  }
  return iVar2;
}



undefined4 /*__cdecl16near*/ FUN_1000_144c(void)

{
  int *piVar1;
  int *piVar2;
  int in_AX;
  undefined2 uVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined2 in_DX;
  uint uVar7;
  undefined2 unaff_DS;
  undefined4 uVar8;
  
  if ((((*(int *)0x37a != 0) && (*(int *)0x1f4 != -2)) && ((in_AX + 1U & 0xfffe) != 0)) &&
     (uVar8 = FUN_1000_142b(), uVar7 = (int)((ulong)uVar8 >> 0x10) - (int)uVar8,
     uVar7 <= uVar7 + 0x10)) {
    uVar8 = FUN_1000_1f3f();
    puVar5 = (uint *)((ulong)uVar8 >> 0x10);
    puVar4 = (uint *)uVar8;
    if (((puVar4 != (uint *)0xffff) && (puVar4 < (uint *)0xfff9)) && (puVar4 < puVar5)) {
      uVar7 = (int)puVar5 - (int)puVar4;
      uVar6 = uVar7 - 4;
      if (uVar6 <= uVar7) {
        if ((*(int *)0x350 == 0) ||
           (piVar2 = *(int **)0x350, puVar5 = puVar4 + -2, puVar5 != (uint *)((int)piVar2 + *piVar2)
           )) {
          if (uVar6 < 0xc) goto LAB_1000_145a;
          *puVar4 = uVar6;
          puVar5 = (uint *)FUN_1000_13bf();
          uVar7 = *puVar5;
        }
        else {
          piVar1 = *(int **)0x350;
          *piVar1 = *piVar1 + uVar7;
          *(undefined2 *)((int)puVar5 + uVar7) = 0xffff;
          ((undefined2 *)((int)puVar5 + uVar7))[1] = 0;
        }
        *puVar5 = uVar7 | 1;
        *(undefined2 *)0x35e = 0xffff;
        piVar1 = (int *)0x360;
        *piVar1 = *piVar1 + 1;
        FUN_1000_1200();
        uVar3 = 1;
        goto LAB_1000_151a;
      }
    }
  }
LAB_1000_145a:
  uVar3 = 0;
LAB_1000_151a:
  return CONCAT22(in_DX,uVar3);
}



undefined2 /*__cdecl16near*/ FUN_1000_1520(void)

{
  return 0;
}



// WARNING: Unable to track spacebase fully for stack
// WARNING: This function may have set the stack pointer

uint /*__cdecl16near*/ FUN_1000_1529(void)

{
  uint *puVar1;
  char *pcVar2;
  code *pcVar3;
  undefined2 uVar4;
  undefined *in_AX;
  uint uVar5;
  char *pcVar6;
  undefined2 *puVar7;
  undefined2 *puVar8;
  undefined2 *puVar9;
  uint unaff_SS;
  undefined2 unaff_DS;
  
  if ((in_AX < &stack0x0000) &&
     ((uVar5 = -((int)in_AX - (int)&stack0x0000), puVar1 = (uint *)0x1fc,
      *puVar1 <= uVar5 && -*puVar1 != (int)in_AX - (int)&stack0x0000 ||
      (uVar5 = unaff_SS, unaff_SS != *(uint *)0x36c)))) {
    return uVar5;
  }
  *(undefined2 *)0x4aa = 1;
  *(undefined2 *)0x4a8 = 0x154b;
  puVar7 = (undefined2 *)0x4a6;
  *(undefined2 *)0x4a6 = 0x1000;
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  pcVar6 = (char *)puVar7[1];
  puVar8 = puVar7 + 2;
  do {
    pcVar2 = pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (*pcVar2 != '\0');
  pcVar3 = (code *)swi(0x21);
  (*pcVar3)();
  *puVar8 = *puVar8;
  puVar8[-1] = 0x577;
  FUN_1000_099c();
  puVar9 = puVar8 + 1;
  pcVar3 = (code *)swi(0x21);
  uVar4 = (*pcVar3)();
  *(undefined2 *)((int)puVar9 + -2) = uVar4;
  return *(uint *)((int)puVar9 + -2);
}



char * /*__cdecl16near*/ FUN_1000_155d(void)

{
  char *pcVar1;
  char *in_AX;
  uint uVar2;
  char *pcVar3;
  char in_DL;
  char *pcVar4;
  undefined2 unaff_DS;
  bool bVar5;
  
  uVar2 = 0xffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar1 = in_AX;
    in_AX = in_AX + 1;
  } while (*pcVar1 != '\0');
  pcVar3 = (char *)~uVar2;
  pcVar4 = in_AX + -1;
  bVar5 = pcVar4 == (char *)0x0;
  do {
    if (pcVar3 == (char *)0x0) break;
    pcVar3 = pcVar3 + -1;
    pcVar1 = pcVar4;
    pcVar4 = pcVar4 + -1;
    bVar5 = in_DL == *pcVar1;
  } while (!bVar5);
  if (bVar5) {
    pcVar3 = pcVar4 + 1;
  }
  return pcVar3;
}



void /*__cdecl16near*/ FUN_1000_1581(undefined2 param_1,undefined2 param_2,undefined2 param_3)

{
  FUN_1000_15a1(param_1,param_2,0,param_3);
  return;
}



int /*__cdecl16near*/ FUN_1000_15a1(char *param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  undefined2 unaff_DS;
  char cVar6;
  char cVar7;
  
  for (; *param_1 == ' '; param_1 = param_1 + 1) {
  }
  cVar6 = '\0';
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)();
  iVar5 = -1;
  if (cVar6 == '\0') {
    iVar5 = iVar2;
  }
  if ((((param_2 & 3) != 0) && (iVar5 != -1)) && (iVar3 = FUN_1000_1f95(), iVar3 == 0)) {
    if ((param_2 & 0x400) != 0) {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      puVar4 = (undefined2 *)FUN_1000_02d1();
      *puVar4 = 7;
      return -1;
    }
    if ((param_2 & 0x40) != 0) {
      cVar6 = '\0';
      pcVar1 = (code *)swi(0x21);
      iVar2 = (*pcVar1)();
      if (cVar6 != '\0') {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        goto LAB_1000_1634;
      }
    }
  }
  if (iVar5 == -1) {
    if (((param_2 & 0x20) != 0) && (iVar2 == 2)) {
      cVar6 = '\0';
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)();
      cVar7 = '\0';
      if (cVar6 == '\0') {
        pcVar1 = (code *)swi(0x21);
        (*pcVar1)();
        if (cVar7 == '\0') {
          cVar6 = '\0';
          pcVar1 = (code *)swi(0x21);
          iVar5 = (*pcVar1)();
          if (cVar6 == '\0') goto LAB_1000_169e;
        }
      }
    }
LAB_1000_1634:
    iVar5 = FUN_1000_0c01();
    return iVar5;
  }
LAB_1000_169e:
  FUN_1000_1fb1();
  FUN_1000_1f95();
  FUN_1000_1ffd();
  return iVar5;
}



int /*__cdecl16near*/ FUN_1000_175e(void)

{
  code *pcVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *in_DX;
  int in_BX;
  char *pcVar8;
  undefined2 unaff_DS;
  char cVar9;
  char *local_16;
  int local_12;
  
  uVar2 = FUN_1000_1fb1();
  if (uVar2 == 0) {
    puVar3 = (undefined2 *)FUN_1000_02d1();
    iVar4 = -1;
    *puVar3 = 4;
  }
  else if ((uVar2 & 1) == 0) {
    puVar3 = (undefined2 *)FUN_1000_02d1();
    iVar4 = -1;
    *puVar3 = 6;
  }
  else {
    cVar9 = '\0';
    if ((uVar2 & 0x40) == 0) {
      iVar4 = 0;
      local_16 = in_DX;
      local_12 = in_BX;
      while( true ) {
        cVar9 = '\0';
        pcVar1 = (code *)swi(0x21);
        iVar5 = (*pcVar1)();
        if (cVar9 != '\0') break;
        if (iVar5 == 0) {
          return iVar4;
        }
        iVar6 = 0;
        pcVar7 = local_16 + iVar5;
        pcVar8 = local_16;
        for (; local_16 < pcVar7; local_16 = local_16 + 1) {
          if (*local_16 == '\x1a') {
            FUN_1000_186c();
            return iVar4;
          }
          if (*local_16 != '\r') {
            iVar4 = iVar4 + 1;
            iVar6 = iVar6 + 1;
            *pcVar8 = *local_16;
            pcVar8 = pcVar8 + 1;
          }
        }
        local_12 = local_12 - iVar6;
        if ((uVar2 & 0x2000) != 0) {
          return iVar4;
        }
        local_16 = pcVar8;
        if (local_12 == 0) {
          return iVar4;
        }
      }
    }
    else {
      pcVar1 = (code *)swi(0x21);
      iVar4 = (*pcVar1)();
      if (cVar9 == '\0') {
        return iVar4;
      }
    }
    iVar4 = FUN_1000_0c01();
  }
  return iVar4;
}



undefined4 /*__cdecl16near*/ FUN_1000_183e(void)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined2 *puVar3;
  undefined2 in_BX;
  undefined2 unaff_DS;
  char in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  if (in_CF == '\0') {
    FUN_1000_1ffd();
    uVar2 = 0;
  }
  else {
    puVar3 = (undefined2 *)FUN_1000_02d1();
    uVar2 = 0xffff;
    *puVar3 = 4;
  }
  return CONCAT22(in_BX,uVar2);
}



undefined4 /*__cdecl16near*/ FUN_1000_186c(void)

{
  code *pcVar1;
  byte bVar2;
  undefined4 uVar3;
  
  bVar2 = &stack0xfffa < (undefined *)0x4;
  pcVar1 = (code *)swi(0x21);
  uVar3 = (*pcVar1)();
  if ((bVar2 & 1) != 0) {
    FUN_1000_0c01();
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



int /*__cdecl16near*/ FUN_1000_18ac(void)

{
  int iVar1;
  int in_CX;
  int in_DX;
  
  if (in_DX < 0) {
    if (in_CX < 0) {
      iVar1 = FUN_1000_18f9();
      return iVar1;
    }
    iVar1 = FUN_1000_18f9();
    return -iVar1;
  }
  if (-1 < in_CX) {
    iVar1 = FUN_1000_18f9();
    return iVar1;
  }
  iVar1 = FUN_1000_18f9();
  return -iVar1;
}



undefined4 /*__cdecl16near*/ FUN_1000_18f9(void)

{
  uint uVar1;
  uint uVar2;
  uint in_AX;
  uint in_CX;
  uint in_DX;
  uint in_BX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  if (in_CX != 0) {
    if (in_CX < in_DX) {
      uVar4 = 0;
      uVar5 = 0;
      iVar3 = 0;
      do {
        bVar6 = CARRY2(in_BX,in_BX);
        in_BX = in_BX * 2;
        bVar7 = CARRY2(in_CX,in_CX) || CARRY2(in_CX * 2,(uint)bVar6);
        in_CX = in_CX * 2 + (uint)bVar6;
        if (bVar7) goto LAB_1000_1959;
        iVar3 = iVar3 + 1;
      } while ((in_CX < in_DX) || ((in_CX <= in_DX && (in_BX <= in_AX))));
      bVar6 = false;
      while( true ) {
        bVar7 = CARRY2(uVar4,uVar4);
        uVar1 = uVar4 * 2;
        uVar4 = uVar1 + bVar6;
        uVar1 = (uint)(bVar7 || CARRY2(uVar1,(uint)bVar6));
        bVar7 = CARRY2(uVar5,uVar5) || CARRY2(uVar5 * 2,uVar1);
        uVar5 = uVar5 * 2 + uVar1;
        iVar3 = iVar3 + -1;
        if (iVar3 < 0) break;
LAB_1000_1959:
        uVar1 = in_CX & 1;
        in_CX = in_CX >> 1 | (uint)bVar7 << 0xf;
        in_BX = in_BX >> 1 | (uint)(uVar1 != 0) << 0xf;
        bVar6 = in_AX < in_BX;
        in_AX = in_AX - in_BX;
        uVar1 = (uint)bVar6;
        bVar7 = in_CX <= in_DX;
        uVar2 = in_DX - in_CX;
        in_DX = uVar2 - uVar1;
        bVar6 = bVar7 && uVar1 <= uVar2;
        if (!bVar7 || uVar1 > uVar2) {
          do {
            bVar6 = CARRY2(uVar4,uVar4);
            uVar4 = uVar4 * 2;
            uVar5 = uVar5 * 2 + (uint)bVar6;
            iVar3 = iVar3 + -1;
            if (iVar3 < 0) goto LAB_1000_197b;
            uVar1 = in_CX & 1;
            in_CX = in_CX >> 1;
            in_BX = in_BX >> 1 | (uint)(uVar1 != 0) << 0xf;
            bVar8 = CARRY2(in_AX,in_BX);
            in_AX = in_AX + in_BX;
            bVar9 = CARRY2(in_DX,in_CX);
            bVar7 = CARRY2(in_DX + in_CX,(uint)bVar8);
            bVar6 = bVar9 || bVar7;
            in_DX = in_DX + in_CX + (uint)bVar8;
          } while (!bVar9 && !bVar7);
        }
      }
LAB_1000_197b:
      return CONCAT22(uVar5,uVar4);
    }
    if ((in_CX == in_DX) && (in_BX <= in_AX)) {
      return 1;
    }
    in_CX = 0;
    in_BX = 0;
LAB_1000_1933:
    return CONCAT22(in_CX,in_BX);
  }
  if (in_BX != 1) {
    if (in_BX == 0) goto LAB_1000_1933;
    if (in_BX <= in_DX) {
      in_CX = in_DX / in_BX;
      in_DX = in_DX % in_BX;
    }
    in_AX = (uint)(CONCAT22(in_DX,in_AX) / (ulong)in_BX);
    in_DX = in_CX;
  }
  return CONCAT22(in_DX,in_AX);
}



char * /*__cdecl16near*/ FUN_1000_1987(void)

{
  char cVar1;
  char *in_AX;
  char *in_DX;
  undefined2 unaff_DS;
  
  for (; cVar1 = *in_DX, *in_AX = cVar1, cVar1 != '\0'; in_DX = in_DX + 1) {
    in_AX = in_AX + 1;
  }
  return in_AX;
}



uint FUN_1000_199e(int *param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  int *in_AX;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *in_CX;
  int *in_DX;
  int *piVar4;
  int *in_BX;
  uint uVar5;
  undefined *puVar6;
  int unaff_DS;
  undefined4 uVar7;
  int local_8;
  
  if (in_DX == (int *)0x0) {
    in_DX = *(int **)0x1f0;
  }
  local_8 = 0;
  if (in_DX != (int *)0x0) {
    for (; *in_DX != 0; in_DX = in_DX + 1) {
      iVar2 = FUN_1000_0586();
      local_8 = local_8 + iVar2 + 1;
    }
  }
  local_8 = local_8 + 1;
  if (param_3 != 0) {
    iVar2 = FUN_1000_0586();
    local_8 = local_8 + iVar2 + 3;
  }
  uVar1 = *(undefined2 *)0x36a;
  *(undefined2 *)0x36a = 0x10;
  uVar7 = FUN_1000_0c61();
  if (((int)uVar7 == 0) && (uVar7 = FUN_1000_0c61(), (int)uVar7 == 0)) {
    puVar3 = (undefined2 *)FUN_1000_02d1();
    *puVar3 = 5;
    puVar3 = (undefined2 *)FUN_1000_02d5();
    *puVar3 = 8;
    *(undefined2 *)0x36a = uVar1;
  }
  else {
    piVar4 = (int *)((ulong)uVar7 >> 0x10);
    *(undefined2 *)0x36a = uVar1;
    *in_BX = (int)uVar7;
    uVar5 = (int)uVar7 + 0xf;
    puVar6 = (undefined *)(uVar5 & 0xfff0);
    *param_1 = (uVar5 >> 4) + unaff_DS;
    *in_CX = puVar6;
    if (piVar4 != (int *)0x0) {
      for (; *piVar4 != 0; piVar4 = piVar4 + 1) {
        iVar2 = FUN_1000_1987();
        puVar6 = (undefined *)(iVar2 + 1);
      }
    }
    *puVar6 = 0;
    if (param_3 != 0) {
      FUN_1000_06cf();
    }
    uVar5 = 0;
    if (*in_AX != 0) {
      while (in_AX = in_AX + 1, *in_AX != 0) {
        uVar7 = FUN_1000_0586();
        uVar5 = (int)((ulong)uVar7 >> 0x10) + (int)uVar7;
      }
    }
    if (uVar5 < 0x7f) {
      *param_2 = 0x90;
      return local_8 + 0xfU >> 4;
    }
    puVar3 = (undefined2 *)FUN_1000_02d1();
    *puVar3 = 2;
    puVar3 = (undefined2 *)FUN_1000_02d5();
    *puVar3 = 10;
    FUN_1000_1200();
  }
  return 0xffff;
}



void /*__cdecl16near*/ FUN_1000_1acc(void)

{
  int in_CX;
  int *in_DX;
  char *in_BX;
  char *pcVar1;
  int *piVar2;
  undefined2 unaff_DS;
  char local_8;
  
  pcVar1 = in_BX;
  if (in_CX == 0) {
    pcVar1 = in_BX + 1;
  }
  if ((*in_DX != 0) && (piVar2 = in_DX + 1, *piVar2 != 0)) {
    while( true ) {
      pcVar1 = (char *)FUN_1000_1987();
      piVar2 = piVar2 + 1;
      if (*piVar2 == 0) break;
      *pcVar1 = ' ';
    }
  }
  if (in_CX == 0) {
    *pcVar1 = '\r';
    local_8 = (char)in_BX;
    *in_BX = ((char)pcVar1 - local_8) + -1;
  }
  else {
    *pcVar1 = '\0';
  }
  return;
}



// WARNING: This function may have set the stack pointer

void FUN_1000_1c5d(undefined2 param_1_00,char *param_1,byte *param_2,int param_3,int param_4,
                  undefined2 param_5,int param_6,undefined2 param_7)

{
  undefined2 uVar1;
  undefined *puVar2;
  byte *pbVar3;
  byte *pbVar4;
  char *pcVar5;
  undefined *puVar6;
  char *pcVar7;
  code **ppcVar8;
  code *pcVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined *puVar13;
  byte *pbVar14;
  undefined *puVar15;
  char *pcVar16;
  undefined2 unaff_SS;
  
  uVar1 = *(undefined2 *)0x1f6;
  pbVar14 = (byte *)0x5c;
  for (iVar10 = 0x24; iVar10 != 0; iVar10 = iVar10 + -1) {
    pbVar3 = pbVar14;
    pbVar14 = pbVar14 + 1;
    *pbVar3 = 0;
  }
  uVar11 = *param_2 + 2;
  if (0x80 < uVar11) {
    uVar11 = 0x80;
  }
  for (; uVar11 != 0; uVar11 = uVar11 - 1) {
    pbVar4 = pbVar14;
    pbVar14 = pbVar14 + 1;
    pbVar3 = param_2;
    param_2 = param_2 + 1;
    *pbVar4 = *pbVar3;
  }
  pcVar9 = (code *)swi(0x21);
  (*pcVar9)();
  pcVar9 = (code *)swi(0x21);
  (*pcVar9)();
  pcVar9 = (code *)swi(0x21);
  (*pcVar9)();
  uVar11 = 0xffff;
  pcVar16 = param_1;
  do {
    if (uVar11 == 0) break;
    uVar11 = uVar11 - 1;
    pcVar5 = pcVar16;
    pcVar16 = pcVar16 + 1;
  } while (*pcVar5 != '\0');
  *(uint *)0x376 = ~uVar11;
  iVar10 = (*(int *)0x2 - (~uVar11 + 0xf >> 4)) + -0x13;
  *(int *)0x374 = iVar10;
  puVar15 = (undefined *)0x0;
  if (param_3 == 0) {
    puVar13 = (undefined *)0x1bb8;
    iVar12 = 0xa5;
  }
  else {
    puVar13 = (undefined *)0x1b20;
    iVar12 = 0x98;
  }
  for (; iVar12 != 0; iVar12 = iVar12 + -1) {
    puVar6 = puVar15;
    puVar15 = puVar15 + 1;
    puVar2 = puVar13;
    puVar13 = puVar13 + 1;
    *puVar6 = *puVar2;
  }
  pcVar16 = (char *)0x130;
  for (iVar12 = *(int *)0x376; iVar12 != 0; iVar12 = iVar12 + -1) {
    pcVar7 = pcVar16;
    pcVar16 = pcVar16 + 1;
    pcVar5 = param_1;
    param_1 = param_1 + 1;
    *pcVar7 = *pcVar5;
  }
  iVar12 = *(int *)0x1f6 + 0x10;
  if (param_3 != 0) {
    *(int *)0x90 = param_4 + iVar12;
    *(undefined2 *)0x92 = param_5;
    *(int *)0x94 = param_6 + iVar12;
    *(undefined2 *)0x96 = param_7;
  }
  ppcVar8 = (code **)0x20e;
  (**ppcVar8)();
  uVar1 = *(undefined2 *)0x1f6;
  *(int *)0x100 = iVar12;
  *(int *)0x102 = iVar12;
                    // WARNING: Could not recover jumptable at 0x00011d5d. Too many branches
                    // WARNING: Treating indirect jump as call
  (*(code *)(ulong)*(uint *)0x372)();
  return;
}



undefined2 /*__cdecl16near*/ FUN_1000_1d61(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined2 *in_CX;
  undefined2 *in_DX;
  undefined2 *in_BX;
  undefined2 unaff_DS;
  byte local_8;
  
  uVar1 = *in_DX;
  uVar2 = in_DX[1];
  uVar3 = in_DX[2];
  uVar4 = in_DX[3];
  uVar5 = in_DX[4];
  uVar6 = in_DX[5];
  uVar7 = in_CX[3];
  uVar8 = *in_CX;
  FUN_1000_200d();
  *in_BX = uVar1;
  in_BX[1] = uVar2;
  in_BX[2] = uVar3;
  in_BX[3] = uVar4;
  in_BX[4] = uVar5;
  in_BX[5] = uVar6;
  in_BX[6] = (uint)(local_8 & 1);
  in_CX[3] = uVar7;
  *in_CX = uVar8;
  return uVar1;
}



void FUN_1000_1e02(uint param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  undefined2 in_AX;
  undefined2 *in_CX;
  uint uVar3;
  undefined2 *in_DX;
  undefined2 in_BX;
  
  for (uVar3 = param_1 >> 1; uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = in_CX;
    in_CX = in_CX + 1;
    puVar1 = in_DX;
    in_DX = in_DX + 1;
    *puVar2 = *puVar1;
  }
  for (uVar3 = (uint)((param_1 & 1) != 0); uVar3 != 0; uVar3 = uVar3 - 1) {
    puVar2 = in_CX;
    in_CX = (undefined2 *)((int)in_CX + 1);
    puVar1 = in_DX;
    in_DX = (undefined2 *)((int)in_DX + 1);
    *(undefined *)puVar2 = *(undefined *)puVar1;
  }
  return;
}



void /*__cdecl16near*/ FUN_1000_1eaf(void)

{
  byte *pbVar1;
  int in_AX;
  int iVar2;
  undefined2 unaff_DS;
  
  if ((*(byte *)(in_AX + 7) & 0x20) == 0) {
    iVar2 = FUN_1000_1f95();
    if ((iVar2 != 0) &&
       (pbVar1 = (byte *)(in_AX + 7), *pbVar1 = *pbVar1 | 0x20, (*(byte *)(in_AX + 7) & 7) == 0)) {
      pbVar1 = (byte *)(in_AX + 7);
      *pbVar1 = *pbVar1 | 2;
    }
  }
  return;
}



int /*__cdecl16near*/ FUN_1000_1ed2(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int in_BX;
  undefined2 unaff_DS;
  byte bVar5;
  char cVar6;
  
  uVar2 = FUN_1000_1fb1();
  if ((uVar2 & 0x80) != 0) {
    bVar5 = 0;
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if ((bVar5 & 1) != 0) goto LAB_1000_1eff;
  }
  cVar6 = '\0';
  pcVar1 = (code *)swi(0x21);
  iVar3 = (*pcVar1)();
  if (cVar6 == '\0') {
    if (iVar3 == in_BX) {
      return iVar3;
    }
    puVar4 = (undefined2 *)FUN_1000_02d1();
    *puVar4 = 0xc;
    return iVar3;
  }
LAB_1000_1eff:
  iVar3 = FUN_1000_0c01();
  return iVar3;
}



undefined4 /*__cdecl16near*/ FUN_1000_1f3f(void)

{
  code *pcVar1;
  uint in_AX;
  undefined2 *puVar2;
  undefined2 uVar3;
  undefined2 in_DX;
  undefined2 extraout_DX;
  uint uVar4;
  int unaff_SS;
  undefined2 unaff_DS;
  char cVar5;
  
  if (*(uint *)0x1fe <= in_AX) {
    uVar4 = in_AX + 0xf >> 4;
    if (uVar4 == 0) {
      uVar4 = 0x1000;
    }
    cVar5 = false;
    if (*(char *)0x1fa == '\0') {
      cVar5 = CARRY2(uVar4,unaff_SS - *(int *)0x1f6);
    }
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)();
    if (cVar5 == '\0') {
      uVar3 = *(undefined2 *)0x1f4;
      *(undefined2 *)0x1f4 = extraout_DX;
      goto LAB_1000_1f90;
    }
  }
  puVar2 = (undefined2 *)FUN_1000_02d1();
  uVar3 = 0xffff;
  *puVar2 = 5;
LAB_1000_1f90:
  return CONCAT22(in_DX,uVar3);
}



undefined4 /*__cdecl16near*/ FUN_1000_1f95(void)

{
  code *pcVar1;
  uint extraout_DX;
  undefined2 in_BX;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)();
  return CONCAT22(in_BX,(uint)((extraout_DX & 0x80) != 0));
}



undefined4 /*__cdecl16near*/ FUN_1000_1fb1(void)

{
  byte *pbVar1;
  uint in_AX;
  undefined2 uVar2;
  undefined2 in_DX;
  int iVar3;
  undefined2 unaff_DS;
  undefined4 uVar4;
  
  if (in_AX < *(uint *)0x37e) {
    if (((int)in_AX < 6) && (iVar3 = in_AX * 2, (*(byte *)(*(int *)0x3a8 + iVar3 + 1) & 0x40) == 0))
    {
      pbVar1 = (byte *)(*(int *)0x3a8 + iVar3 + 1);
      *pbVar1 = *pbVar1 | 0x40;
      uVar4 = FUN_1000_1f95();
      in_AX = (uint)((ulong)uVar4 >> 0x10);
      if ((int)uVar4 != 0) {
        pbVar1 = (byte *)(iVar3 + *(int *)0x3a8 + 1);
        *pbVar1 = *pbVar1 | 0x20;
      }
    }
    uVar2 = *(undefined2 *)(*(int *)0x3a8 + in_AX * 2);
  }
  else {
    uVar2 = 0;
  }
  return CONCAT22(in_DX,uVar2);
}



void /*__cdecl16near*/ FUN_1000_1ffd(void)

{
  int in_AX;
  uint in_DX;
  undefined2 unaff_DS;
  
  *(uint *)(*(int *)0x3a8 + in_AX * 2) = in_DX | 0x4000;
  return;
}



void /*__cdecl16near*/ FUN_1000_200d(void)

{
  FUN_1000_2230();
  return;
}



void /*__cdecl16near*/ FUN_1000_2230(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int in_DX;
  int iVar3;
  uint in_BX;
  uint uVar4;
  undefined2 unaff_BP;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  undefined2 unaff_DS;
  byte bVar5;
  byte bVar6;
  byte in_AF;
  byte bVar7;
  byte bVar8;
  byte in_TF;
  byte in_IF;
  byte bVar9;
  byte in_NT;
  
  uVar4 = (in_BX & 0xff) * 3;
  bVar5 = 0xdd6a < uVar4;
  bVar9 = SCARRY2(uVar4,0x2295);
  uVar4 = uVar4 + 0x2295;
  bVar8 = 0;
  bVar7 = uVar4 == 0;
  bVar6 = (POPCOUNT(uVar4 & 0xff) & 1U) == 0;
  uVar2 = 0x1000;
  iVar3 = in_DX;
  uVar1 = FUN_1000_2273();
  *(uint *)(in_DX + 0x12) =
       (uint)(in_NT & 1) * 0x4000 | (uint)(bVar9 & 1) * 0x800 | (uint)(in_IF & 1) * 0x200 |
       (uint)(in_TF & 1) * 0x100 | (uint)(bVar8 & 1) * 0x80 | (uint)(bVar7 & 1) * 0x40 |
       (uint)(in_AF & 1) * 0x10 | (uint)(bVar6 & 1) * 4 | (uint)(bVar5 & 1);
  *(undefined2 *)CONCAT22(unaff_DS,in_DX) = uVar1;
  *(undefined2 *)(in_DX + 4) = uVar2;
  *(int *)(in_DX + 6) = iVar3;
  *(undefined2 *)(in_DX + 10) = unaff_SI;
  *(undefined2 *)(in_DX + 0xc) = unaff_DI;
  *(undefined2 *)(in_DX + 8) = unaff_BP;
  *(undefined2 *)(in_DX + 0xe) = unaff_DS;
  *(uint *)(in_DX + 2) = uVar4;
  *(undefined2 *)(in_DX + 0x10) = 0x1000;
  return;
}



undefined2 /*__cdecl16far*/ FUN_1000_2273(void)

{
  undefined2 *in_AX;
  undefined2 in_DX;
  
  return *in_AX;
}


