
#ifndef __OTA_SHELL__
#define __OTA_SHELL__

#include <zephyr.h>
#include <misc/printk.h>
#include <flash_map.h>

#define OTA_ERR(fmt, ...)   printf("[ERR] "fmt"\n", ##__VA_ARGS__)
#define OTA_WARN(fmt, ...)  printf("[WARN] "fmt"\n", ##__VA_ARGS__)
#define OTA_INFO(fmt, ...)  printf("[INFO] "fmt"\n", ##__VA_ARGS__)

#define OTA_FA_SLOT_0                       1
#define OTA_FA_SLOT_1                       2
#define OTA_FA_SCRATCH                      3
#define OTA_FA_MODEM_0                      4
#define OTA_FA_MODEM_1                      5

#define OTA_FA_MODEM_0_ADDR      (0x02000000 + FLASH_AREA_MODEM_0_OFFSET)
#define OTA_FA_MODEM_1_ADDR      (0x02000000 + FLASH_AREA_MODEM_1_OFFSET)


#define FLASH_ERASE_BLOCK_SIZE	(64 * 1024)

/*"74.207.248.168" "139.196.142.65" */
#define OTA_SVR_ADDR    "192.168.1.102"
#define OTA_SVR_PORT    80

#define OTA_MODEM_BIN_URL    "/ota/wcn-modem-96b_ivy5661.bin"
#define OTA_KERNEL_BIN_URL   "/ota/zephyr-signed-ota-96b_ivy5661.bin"
#define OTA_TEST_BIN_URL     "/sites/default/files/banner/sc9863.jpg"

#define OTA_MODEM_BIN_SIZE      618512	/*byte */
#define OTA_KERNEL_BIN_SIZE     383284	/*byte */
#define OTA_TEST_BIN_SIZE       147992

#define HTTP_RSP_STATS_NOT_FOUND	"Not Found"
#define HTTP_RSP_STATS_PART_CONT	"Partial Content"

#define OTA_HTTP_REQ_TIMEOUT K_SECONDS(10)
#define OTA_HTTP_REPEAT_REQ_MAX 10
#define WAIT_TIME (OTA_HTTP_REQ_TIMEOUT * 2)

#define OTA_COUNT_EACH_ONE      2048	/*64*1024 //64Kb */

#define OTA_MODEM_START_ADDR_OFF	0x0000D000
#define OTA_MODEM_START_ADDR_SIZE	0x1000

enum OTA_TYPE {
	OTA_KERNEL,
	OTA_MODEM,
	OTA_OTHER
};

struct ota_bin_cfg {
	char *host_ip;
	unsigned short	host_port;
	char *url_path;
	int	file_len;

};

/*define the download operation*/
struct stc_ota_cfg {
	u8_t type;
	u32_t addr;
	struct ota_bin_cfg bin_cfg;

};
#endif /*__OTA_SHELL__*/
