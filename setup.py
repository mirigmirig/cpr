try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension

config = {
    'description': 'cpr project',
    'author': 'mirig',
    'url': 'https://github.com/mirigmirig/cpr',
    'download_url': 'https://github.com/mirigmirig/cpr',
    'author_email': 'mirig.swdeveloper@gmail.com',
    'version': '0.1',
    'install_requires': ['nose'],
    'packages': ['cpr'],
    'scripts': [],
    'ext_modules':[Extension('hello', ['cmodules/hello.c'] )],
    'name': 'cpr'
}

setup(**config)
