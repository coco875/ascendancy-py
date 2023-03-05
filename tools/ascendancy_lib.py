import class_ascendancy

# add path to ascendancy_lib.dll
import sys
sys.path.append("tools")

import clr
clr.AddReference("ii.AscendancyLib")
import ii.AscendancyLib as asc
import System

save_reader = asc.Reader.SavReader()
save_writer = asc.Writer.SavWriter()

def load_save(filename:str) -> class_ascendancy.SavFile:
    """public SavFile Load(string filename)"""
    return save_reader.Load(filename)

def save_save(save:class_ascendancy.SavFile, filename:str):
    """public void Save(SavFile save, string filename)"""
    save_writer.Save(filename, save)

def bytes_to_Struct(byte:bytes, struct_type:System.Type) -> object:
    byte_list = System.Array[System.Byte](byte)
    handle = System.Runtime.InteropServices.GCHandle.Alloc(byte_list, System.Runtime.InteropServices.GCHandleType.Pinned)
    s = System.Runtime.InteropServices.Marshal.PtrToStructure(handle.AddrOfPinnedObject(), struct_type)
    handle.Free()
    return s

def Struct_to_bytes(struct:object) -> bytes:
    return asc.Common.WriteStruct(struct)

def size_of_struct(struct_type:System.Type) -> int:
    """public static int SizeOfStruct<T>()"""
    return System.Runtime.InteropServices.Marshal.SizeOf(struct_type)
