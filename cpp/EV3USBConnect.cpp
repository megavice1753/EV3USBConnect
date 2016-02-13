#include <jni.h>
#include "EV3USBConnect.h"
#include "hidapi.h"
#include <iostream>

using namespace std;

JNIEXPORT jbyteArray JNICALL Java_EV3USBConnect_Connector_readWrite(JNIEnv * env, jclass cls, jbyteArray inArray) {
	if (inArray == NULL) {
		return NULL;
	}
	jsize inLength = env->GetArrayLength(inArray);
	hid_device *handle;
	handle = hid_open(0x694, 0x05, NULL);
	char * input = new char[inLength + 1];
	input[0] = 0;//in hid api first byte must be zero value
	++input;
	env->GetByteArrayRegion(inArray, 0, inLength, (jbyte*)input);
	--input;
	cout << "native in:\n";
	for (int i = 1; i  < inLength + 1; ++i) {
		cout << (int)input[i] << " ";
	}
	cout << "\n";
	hid_write(handle, (const unsigned char *)input, inLength + 1);
	int bufLength = hid_read_length(handle);
	unsigned char * resp = new unsigned char[bufLength];
	hid_read(handle, resp, bufLength);
	jsize outLength = (jsize) (((resp[1] & 0xff) << 8) | (resp[0] & 0xff)) + 2;
	jbyteArray outArray = env->NewByteArray(outLength);
	env->SetByteArrayRegion(outArray, 0, outLength, (const jbyte*)resp);
	cout << "native out:\n";
	for (int i = 0; i  < outLength; ++i) {
		cout << (int)resp[i] << " ";
	}
	cout << "\n";
	delete [] resp;
	delete [] input;
	hid_close(handle);
	return outArray;
}

JNIEXPORT void JNICALL Java_EV3USBConnect_Connector_write(JNIEnv * env, jclass cls, jbyteArray inArray) {
	if (inArray == NULL) {
		return;
	}
	jsize inLength = env->GetArrayLength(inArray);
	hid_device *handle;
	handle = hid_open(0x694, 0x05, NULL);
	char * input = new char[inLength + 1];
	input[0] = 0;//in hid api first byte must be zero value
	++input;
	env->GetByteArrayRegion(inArray, 0, inLength, (jbyte*)input);
	--input;
	cout <<"native in: \n";
	for (int i = 1; i  < inLength + 1; ++i) {
		cout << (int)input[i] << " ";
	}
	cout << "\n";
	hid_write(handle, (const unsigned char *)input, inLength + 1);
	delete [] input;
	hid_close(handle);
	return;
}