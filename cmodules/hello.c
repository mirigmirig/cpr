#include <Python.h>
#include <string.h>

static char module_docstring[] = "This is module docstring";
static char message_docstring[] = "This is message docstring";

static PyObject*
message_hello(PyObject *self, PyObject *args)
{
	char *fromPython, result[1024];
	if(!PyArg_Parse(args, "(s)", &fromPython))
		return NULL;
	else{

		strcpy(result, "Hello");
		strcat(result, fromPython);
		return Py_BuildValue("s", result);
	}
}

static PyMethodDef HelloMethods[] = {
{"message", message_hello, METH_VARARGS, message_docstring},
{NULL, NULL, 0, NULL}
};

/* module initializer */
PyMODINIT_FUNC
inithello(void) /* called on first import */
{ /* name matters if loaded dynamically */

	PyObject *m = Py_InitModule3("hello", HelloMethods, module_docstring);
	if (m==NULL) return;
}
