#ifndef HIDAPI_H__
#define HIDAPI_H__

#include <wchar.h>

#ifdef _WIN32
      #define HID_API_EXPORT __declspec(dllexport)
      #define HID_API_CALL
#else
      #define HID_API_EXPORT /**< API export macro */
      #define HID_API_CALL /**< API call macro */
#endif

#define HID_API_EXPORT_CALL HID_API_EXPORT HID_API_CALL /**< API export and call macro*/

#ifdef __cplusplus
extern "C" {
#endif
		struct hid_device_;
		typedef struct hid_device_ hid_device; /**< opaque hidapi structure */

		/** hidapi info structure */
		struct hid_device_info {
			/** Platform-specific device path */
			char *path;
			/** Device Vendor ID */
			unsigned short vendor_id;
			/** Device Product ID */
			unsigned short product_id;
			/** Serial Number */
			wchar_t *serial_number;
			/** Device Release Number in binary-coded decimal,
			    also known as Device Version Number */
			unsigned short release_number;
			/** Manufacturer String */
			wchar_t *manufacturer_string;
			/** Product string */
			wchar_t *product_string;
			/** Usage Page for this Device/Interface
			    (Windows/Mac only). */
			unsigned short usage_page;
			/** Usage for this Device/Interface
			    (Windows/Mac only).*/
			unsigned short usage;
			/** The USB interface which this logical device
			    represents. Valid on both Linux implementations
			    in all cases, and valid on the Windows implementation
			    only if the device contains more than one interface. */
			int interface_number;

			/** Pointer to the next device */
			struct hid_device_info *next;
		};


		int HID_API_EXPORT HID_API_CALL hid_init(void);

		int HID_API_EXPORT HID_API_CALL hid_exit(void);

		struct hid_device_info HID_API_EXPORT * HID_API_CALL hid_enumerate(unsigned short vendor_id, unsigned short product_id);

		void  HID_API_EXPORT HID_API_CALL hid_free_enumeration(struct hid_device_info *devs);

		HID_API_EXPORT hid_device * HID_API_CALL hid_open(unsigned short vendor_id, unsigned short product_id, const wchar_t *serial_number);

		HID_API_EXPORT hid_device * HID_API_CALL hid_open_path(const char *path);

		int  HID_API_EXPORT HID_API_CALL hid_write(hid_device *device, const unsigned char *data, size_t length);

		size_t HID_API_EXPORT HID_API_CALL hid_read_length(hid_device *dev);

		int HID_API_EXPORT HID_API_CALL hid_read_timeout(hid_device *dev, unsigned char *data, size_t length, int milliseconds);

		int  HID_API_EXPORT HID_API_CALL hid_read(hid_device *device, unsigned char *data, size_t length);

		int  HID_API_EXPORT HID_API_CALL hid_set_nonblocking(hid_device *device, int nonblock);

		int HID_API_EXPORT HID_API_CALL hid_send_feature_report(hid_device *device, const unsigned char *data, size_t length);

		int HID_API_EXPORT HID_API_CALL hid_get_feature_report(hid_device *device, unsigned char *data, size_t length);

		void HID_API_EXPORT HID_API_CALL hid_close(hid_device *device);

		int HID_API_EXPORT_CALL hid_get_manufacturer_string(hid_device *device, wchar_t *string, size_t maxlen);

		int HID_API_EXPORT_CALL hid_get_product_string(hid_device *device, wchar_t *string, size_t maxlen);

		int HID_API_EXPORT_CALL hid_get_serial_number_string(hid_device *device, wchar_t *string, size_t maxlen);

		int HID_API_EXPORT_CALL hid_get_indexed_string(hid_device *device, int string_index, wchar_t *string, size_t maxlen);

		HID_API_EXPORT const wchar_t* HID_API_CALL hid_error(hid_device *device);


#ifdef __cplusplus
}
#endif

#endif

