from setuptools import setup
from Cython.Build import cythonize

setup(
    ext_modules = cythonize("testcy.pyx", annotate=True)
)

# $ python3 setup.py build_ext --inplace