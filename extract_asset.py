from tools import cob, shape

import os

def get_all_cob_files(directory):
    files = []
    for root, dirs, filenames in os.walk(directory):
        for filename in filenames:
            if filename.endswith('.cob'):
                files.append(os.path.join(root, filename))
    return files

def extract_all_cob_files(directory):
    files = get_all_cob_files(directory)
    for filename in files:
        _cob = cob.cob_archive(filename)
        for i in range(len(_cob.files)):
            parent = os.path.join("assets", _cob.files[i].path)
            if not os.path.isdir(parent):
                os.makedirs(parent)
            _cob.file_write(i, os.path.join(parent, _cob.files[i].name))

def get_all_shp_files(directory):
    files = []
    for root, dirs, filenames in os.walk(directory):
        for filename in filenames:
            if filename.endswith('.shp'):
                files.append(os.path.join(root, filename))
    return files

def extract_all_shp_files(directory):
    files = get_all_shp_files(directory)
    palette = shape.read_palette(open("assets/data/game.pal", 'rb'))
    palette2 = shape.read_palette(open("assets/data/logo.pal", 'rb'))
    for filename in files:
        shape.extract_shapes(filename, palette)
            

if __name__ == "__main__":
    extract_all_cob_files("./game")
    extract_all_shp_files("./assets/data")
    