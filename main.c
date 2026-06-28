#define _DEFAULT_SOURCE
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <math.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <time.h>

#include <wayland-client.h>
#include <linux/input-event-codes.h>
#include <xkbcommon/xkbcommon.h>
#include <cairo/cairo.h>

#define GRID_CELLS  9
#define CELL_PX     16
#define CORNER_R    6
#define WIN_SIZE    (GRID_CELLS * CELL_PX)
#define HALF        (GRID_CELLS / 2)
#define GAP         20
#define SW_W        155
#define SW_H        52

#ifndef WLR_LAYER_SHELL_UNSTABLE_V1_CLIENT_PROTOCOL_H
#define WLR_LAYER_SHELL_UNSTABLE_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_output;
struct wl_surface;
struct xdg_popup;
struct zwlr_layer_shell_v1;
struct zwlr_layer_surface_v1;

#ifndef ZWLR_LAYER_SHELL_V1_INTERFACE
#define ZWLR_LAYER_SHELL_V1_INTERFACE

extern const struct wl_interface zwlr_layer_shell_v1_interface;
#endif
#ifndef ZWLR_LAYER_SURFACE_V1_INTERFACE
#define ZWLR_LAYER_SURFACE_V1_INTERFACE

extern const struct wl_interface zwlr_layer_surface_v1_interface;
#endif

#ifndef ZWLR_LAYER_SHELL_V1_ERROR_ENUM
#define ZWLR_LAYER_SHELL_V1_ERROR_ENUM
enum zwlr_layer_shell_v1_error {

	ZWLR_LAYER_SHELL_V1_ERROR_ROLE = 0,

	ZWLR_LAYER_SHELL_V1_ERROR_INVALID_LAYER = 1,

	ZWLR_LAYER_SHELL_V1_ERROR_ALREADY_CONSTRUCTED = 2,
};
#endif

#ifndef ZWLR_LAYER_SHELL_V1_LAYER_ENUM
#define ZWLR_LAYER_SHELL_V1_LAYER_ENUM

enum zwlr_layer_shell_v1_layer {
	ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND = 0,
	ZWLR_LAYER_SHELL_V1_LAYER_BOTTOM = 1,
	ZWLR_LAYER_SHELL_V1_LAYER_TOP = 2,
	ZWLR_LAYER_SHELL_V1_LAYER_OVERLAY = 3,
};
#endif

#define ZWLR_LAYER_SHELL_V1_GET_LAYER_SURFACE 0
#define ZWLR_LAYER_SHELL_V1_DESTROY 1

#define ZWLR_LAYER_SHELL_V1_GET_LAYER_SURFACE_SINCE_VERSION 1

#define ZWLR_LAYER_SHELL_V1_DESTROY_SINCE_VERSION 3

static inline void
zwlr_layer_shell_v1_set_user_data(struct zwlr_layer_shell_v1 *zwlr_layer_shell_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwlr_layer_shell_v1, user_data);
}

static inline void *
zwlr_layer_shell_v1_get_user_data(struct zwlr_layer_shell_v1 *zwlr_layer_shell_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwlr_layer_shell_v1);
}

static inline uint32_t
zwlr_layer_shell_v1_get_version(struct zwlr_layer_shell_v1 *zwlr_layer_shell_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwlr_layer_shell_v1);
}

static inline struct zwlr_layer_surface_v1 *
zwlr_layer_shell_v1_get_layer_surface(struct zwlr_layer_shell_v1 *zwlr_layer_shell_v1, struct wl_surface *surface, struct wl_output *output, uint32_t layer, const char *namespace)
{
	struct wl_proxy *id;

	id = wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_shell_v1,
			 ZWLR_LAYER_SHELL_V1_GET_LAYER_SURFACE, &zwlr_layer_surface_v1_interface, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_shell_v1), 0, NULL, surface, output, layer, namespace);

	return (struct zwlr_layer_surface_v1 *) id;
}

static inline void
zwlr_layer_shell_v1_destroy(struct zwlr_layer_shell_v1 *zwlr_layer_shell_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_shell_v1,
			 ZWLR_LAYER_SHELL_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_shell_v1), WL_MARSHAL_FLAG_DESTROY);
}

#ifndef ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ENUM
#define ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ENUM

enum zwlr_layer_surface_v1_keyboard_interactivity {

	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_NONE = 0,

	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_EXCLUSIVE = 1,

	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ON_DEMAND = 2,
};

#define ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ON_DEMAND_SINCE_VERSION 4
#endif

#ifndef ZWLR_LAYER_SURFACE_V1_ERROR_ENUM
#define ZWLR_LAYER_SURFACE_V1_ERROR_ENUM
enum zwlr_layer_surface_v1_error {

	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_SURFACE_STATE = 0,

	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_SIZE = 1,

	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_ANCHOR = 2,

	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_KEYBOARD_INTERACTIVITY = 3,
};
#endif

#ifndef ZWLR_LAYER_SURFACE_V1_ANCHOR_ENUM
#define ZWLR_LAYER_SURFACE_V1_ANCHOR_ENUM
enum zwlr_layer_surface_v1_anchor {

	ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP = 1,

	ZWLR_LAYER_SURFACE_V1_ANCHOR_BOTTOM = 2,

	ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT = 4,

	ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT = 8,
};
#endif

struct zwlr_layer_surface_v1_listener {

	void (*configure)(void *data,
			  struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1,
			  uint32_t serial,
			  uint32_t width,
			  uint32_t height);

	void (*closed)(void *data,
		       struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1);
};

static inline int
zwlr_layer_surface_v1_add_listener(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1,
				   const struct zwlr_layer_surface_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwlr_layer_surface_v1,
				     (void (**)(void)) listener, data);
}

#define ZWLR_LAYER_SURFACE_V1_SET_SIZE 0
#define ZWLR_LAYER_SURFACE_V1_SET_ANCHOR 1
#define ZWLR_LAYER_SURFACE_V1_SET_EXCLUSIVE_ZONE 2
#define ZWLR_LAYER_SURFACE_V1_SET_MARGIN 3
#define ZWLR_LAYER_SURFACE_V1_SET_KEYBOARD_INTERACTIVITY 4
#define ZWLR_LAYER_SURFACE_V1_GET_POPUP 5
#define ZWLR_LAYER_SURFACE_V1_ACK_CONFIGURE 6
#define ZWLR_LAYER_SURFACE_V1_DESTROY 7
#define ZWLR_LAYER_SURFACE_V1_SET_LAYER 8

#define ZWLR_LAYER_SURFACE_V1_CONFIGURE_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_CLOSED_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_SET_SIZE_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_SET_ANCHOR_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_SET_EXCLUSIVE_ZONE_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_SET_MARGIN_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_SET_KEYBOARD_INTERACTIVITY_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_GET_POPUP_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_ACK_CONFIGURE_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_DESTROY_SINCE_VERSION 1

#define ZWLR_LAYER_SURFACE_V1_SET_LAYER_SINCE_VERSION 2

static inline void
zwlr_layer_surface_v1_set_user_data(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwlr_layer_surface_v1, user_data);
}

static inline void *
zwlr_layer_surface_v1_get_user_data(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwlr_layer_surface_v1);
}

static inline uint32_t
zwlr_layer_surface_v1_get_version(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1);
}

static inline void
zwlr_layer_surface_v1_set_size(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, uint32_t width, uint32_t height)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_SET_SIZE, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), 0, width, height);
}

static inline void
zwlr_layer_surface_v1_set_anchor(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, uint32_t anchor)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_SET_ANCHOR, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), 0, anchor);
}

static inline void
zwlr_layer_surface_v1_set_exclusive_zone(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, int32_t zone)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_SET_EXCLUSIVE_ZONE, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), 0, zone);
}

static inline void
zwlr_layer_surface_v1_set_margin(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, int32_t top, int32_t right, int32_t bottom, int32_t left)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_SET_MARGIN, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), 0, top, right, bottom, left);
}

static inline void
zwlr_layer_surface_v1_set_keyboard_interactivity(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, uint32_t keyboard_interactivity)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_SET_KEYBOARD_INTERACTIVITY, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), 0, keyboard_interactivity);
}

static inline void
zwlr_layer_surface_v1_get_popup(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, struct xdg_popup *popup)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_GET_POPUP, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), 0, popup);
}

static inline void
zwlr_layer_surface_v1_ack_configure(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, uint32_t serial)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_ACK_CONFIGURE, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), 0, serial);
}

static inline void
zwlr_layer_surface_v1_destroy(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), WL_MARSHAL_FLAG_DESTROY);
}

static inline void
zwlr_layer_surface_v1_set_layer(struct zwlr_layer_surface_v1 *zwlr_layer_surface_v1, uint32_t layer)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_layer_surface_v1,
			 ZWLR_LAYER_SURFACE_V1_SET_LAYER, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_layer_surface_v1), 0, layer);
}

#ifdef  __cplusplus
}
#endif

#endif

#ifndef WLR_SCREENCOPY_UNSTABLE_V1_CLIENT_PROTOCOL_H
#define WLR_SCREENCOPY_UNSTABLE_V1_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_buffer;
struct wl_output;
struct zwlr_screencopy_frame_v1;
struct zwlr_screencopy_manager_v1;

#ifndef ZWLR_SCREENCOPY_MANAGER_V1_INTERFACE
#define ZWLR_SCREENCOPY_MANAGER_V1_INTERFACE

extern const struct wl_interface zwlr_screencopy_manager_v1_interface;
#endif
#ifndef ZWLR_SCREENCOPY_FRAME_V1_INTERFACE
#define ZWLR_SCREENCOPY_FRAME_V1_INTERFACE

extern const struct wl_interface zwlr_screencopy_frame_v1_interface;
#endif

#define ZWLR_SCREENCOPY_MANAGER_V1_CAPTURE_OUTPUT 0
#define ZWLR_SCREENCOPY_MANAGER_V1_CAPTURE_OUTPUT_REGION 1
#define ZWLR_SCREENCOPY_MANAGER_V1_DESTROY 2

#define ZWLR_SCREENCOPY_MANAGER_V1_CAPTURE_OUTPUT_SINCE_VERSION 1

#define ZWLR_SCREENCOPY_MANAGER_V1_CAPTURE_OUTPUT_REGION_SINCE_VERSION 1

#define ZWLR_SCREENCOPY_MANAGER_V1_DESTROY_SINCE_VERSION 1

static inline void
zwlr_screencopy_manager_v1_set_user_data(struct zwlr_screencopy_manager_v1 *zwlr_screencopy_manager_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwlr_screencopy_manager_v1, user_data);
}

static inline void *
zwlr_screencopy_manager_v1_get_user_data(struct zwlr_screencopy_manager_v1 *zwlr_screencopy_manager_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwlr_screencopy_manager_v1);
}

static inline uint32_t
zwlr_screencopy_manager_v1_get_version(struct zwlr_screencopy_manager_v1 *zwlr_screencopy_manager_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwlr_screencopy_manager_v1);
}

static inline struct zwlr_screencopy_frame_v1 *
zwlr_screencopy_manager_v1_capture_output(struct zwlr_screencopy_manager_v1 *zwlr_screencopy_manager_v1, int32_t overlay_cursor, struct wl_output *output)
{
	struct wl_proxy *frame;

	frame = wl_proxy_marshal_flags((struct wl_proxy *) zwlr_screencopy_manager_v1,
			 ZWLR_SCREENCOPY_MANAGER_V1_CAPTURE_OUTPUT, &zwlr_screencopy_frame_v1_interface, wl_proxy_get_version((struct wl_proxy *) zwlr_screencopy_manager_v1), 0, NULL, overlay_cursor, output);

	return (struct zwlr_screencopy_frame_v1 *) frame;
}

static inline struct zwlr_screencopy_frame_v1 *
zwlr_screencopy_manager_v1_capture_output_region(struct zwlr_screencopy_manager_v1 *zwlr_screencopy_manager_v1, int32_t overlay_cursor, struct wl_output *output, int32_t x, int32_t y, int32_t width, int32_t height)
{
	struct wl_proxy *frame;

	frame = wl_proxy_marshal_flags((struct wl_proxy *) zwlr_screencopy_manager_v1,
			 ZWLR_SCREENCOPY_MANAGER_V1_CAPTURE_OUTPUT_REGION, &zwlr_screencopy_frame_v1_interface, wl_proxy_get_version((struct wl_proxy *) zwlr_screencopy_manager_v1), 0, NULL, overlay_cursor, output, x, y, width, height);

	return (struct zwlr_screencopy_frame_v1 *) frame;
}

static inline void
zwlr_screencopy_manager_v1_destroy(struct zwlr_screencopy_manager_v1 *zwlr_screencopy_manager_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_screencopy_manager_v1,
			 ZWLR_SCREENCOPY_MANAGER_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_screencopy_manager_v1), WL_MARSHAL_FLAG_DESTROY);
}

#ifndef ZWLR_SCREENCOPY_FRAME_V1_ERROR_ENUM
#define ZWLR_SCREENCOPY_FRAME_V1_ERROR_ENUM
enum zwlr_screencopy_frame_v1_error {

	ZWLR_SCREENCOPY_FRAME_V1_ERROR_ALREADY_USED = 0,

	ZWLR_SCREENCOPY_FRAME_V1_ERROR_INVALID_BUFFER = 1,
};
#endif

#ifndef ZWLR_SCREENCOPY_FRAME_V1_FLAGS_ENUM
#define ZWLR_SCREENCOPY_FRAME_V1_FLAGS_ENUM
enum zwlr_screencopy_frame_v1_flags {

	ZWLR_SCREENCOPY_FRAME_V1_FLAGS_Y_INVERT = 1,
};
#endif

struct zwlr_screencopy_frame_v1_listener {

	void (*buffer)(void *data,
		       struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1,
		       uint32_t format,
		       uint32_t width,
		       uint32_t height,
		       uint32_t stride);

	void (*flags)(void *data,
		      struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1,
		      uint32_t flags);

	void (*ready)(void *data,
		      struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1,
		      uint32_t tv_sec_hi,
		      uint32_t tv_sec_lo,
		      uint32_t tv_nsec);

	void (*failed)(void *data,
		       struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1);

	void (*damage)(void *data,
		       struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1,
		       uint32_t x,
		       uint32_t y,
		       uint32_t width,
		       uint32_t height);

	void (*linux_dmabuf)(void *data,
			     struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1,
			     uint32_t format,
			     uint32_t width,
			     uint32_t height);

	void (*buffer_done)(void *data,
			    struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1);
};

static inline int
zwlr_screencopy_frame_v1_add_listener(struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1,
				      const struct zwlr_screencopy_frame_v1_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) zwlr_screencopy_frame_v1,
				     (void (**)(void)) listener, data);
}

#define ZWLR_SCREENCOPY_FRAME_V1_COPY 0
#define ZWLR_SCREENCOPY_FRAME_V1_DESTROY 1
#define ZWLR_SCREENCOPY_FRAME_V1_COPY_WITH_DAMAGE 2

#define ZWLR_SCREENCOPY_FRAME_V1_BUFFER_SINCE_VERSION 1

#define ZWLR_SCREENCOPY_FRAME_V1_FLAGS_SINCE_VERSION 1

#define ZWLR_SCREENCOPY_FRAME_V1_READY_SINCE_VERSION 1

#define ZWLR_SCREENCOPY_FRAME_V1_FAILED_SINCE_VERSION 1

#define ZWLR_SCREENCOPY_FRAME_V1_DAMAGE_SINCE_VERSION 2

#define ZWLR_SCREENCOPY_FRAME_V1_LINUX_DMABUF_SINCE_VERSION 3

#define ZWLR_SCREENCOPY_FRAME_V1_BUFFER_DONE_SINCE_VERSION 3

#define ZWLR_SCREENCOPY_FRAME_V1_COPY_SINCE_VERSION 1

#define ZWLR_SCREENCOPY_FRAME_V1_DESTROY_SINCE_VERSION 1

#define ZWLR_SCREENCOPY_FRAME_V1_COPY_WITH_DAMAGE_SINCE_VERSION 2

static inline void
zwlr_screencopy_frame_v1_set_user_data(struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) zwlr_screencopy_frame_v1, user_data);
}

static inline void *
zwlr_screencopy_frame_v1_get_user_data(struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1)
{
	return wl_proxy_get_user_data((struct wl_proxy *) zwlr_screencopy_frame_v1);
}

static inline uint32_t
zwlr_screencopy_frame_v1_get_version(struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1)
{
	return wl_proxy_get_version((struct wl_proxy *) zwlr_screencopy_frame_v1);
}

static inline void
zwlr_screencopy_frame_v1_copy(struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1, struct wl_buffer *buffer)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_screencopy_frame_v1,
			 ZWLR_SCREENCOPY_FRAME_V1_COPY, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_screencopy_frame_v1), 0, buffer);
}

static inline void
zwlr_screencopy_frame_v1_destroy(struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_screencopy_frame_v1,
			 ZWLR_SCREENCOPY_FRAME_V1_DESTROY, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_screencopy_frame_v1), WL_MARSHAL_FLAG_DESTROY);
}

static inline void
zwlr_screencopy_frame_v1_copy_with_damage(struct zwlr_screencopy_frame_v1 *zwlr_screencopy_frame_v1, struct wl_buffer *buffer)
{
	wl_proxy_marshal_flags((struct wl_proxy *) zwlr_screencopy_frame_v1,
			 ZWLR_SCREENCOPY_FRAME_V1_COPY_WITH_DAMAGE, NULL, wl_proxy_get_version((struct wl_proxy *) zwlr_screencopy_frame_v1), 0, buffer);
}

#ifdef  __cplusplus
}
#endif

#endif

static const struct wl_interface xdg_popup_interface = {
	"xdg_popup", 1, 0, NULL, 0, NULL,
};

#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#if (__has_attribute(visibility) || defined(__GNUC__) && __GNUC__ >= 4)
#define WL_PRIVATE __attribute__ ((visibility("hidden")))
#else
#define WL_PRIVATE
#endif

extern const struct wl_interface wl_output_interface;
extern const struct wl_interface wl_surface_interface;
extern const struct wl_interface xdg_popup_interface;
extern const struct wl_interface zwlr_layer_surface_v1_interface;

static const struct wl_interface *wlr_layer_shell_unstable_v1_types[] = {
	NULL,
	NULL,
	NULL,
	NULL,
	&zwlr_layer_surface_v1_interface,
	&wl_surface_interface,
	&wl_output_interface,
	NULL,
	NULL,
	&xdg_popup_interface,
};

static const struct wl_message zwlr_layer_shell_v1_requests[] = {
	{ "get_layer_surface", "no?ous", wlr_layer_shell_unstable_v1_types + 4 },
	{ "destroy", "3", wlr_layer_shell_unstable_v1_types + 0 },
};

WL_PRIVATE const struct wl_interface zwlr_layer_shell_v1_interface = {
	"zwlr_layer_shell_v1", 4,
	2, zwlr_layer_shell_v1_requests,
	0, NULL,
};

static const struct wl_message zwlr_layer_surface_v1_requests[] = {
	{ "set_size", "uu", wlr_layer_shell_unstable_v1_types + 0 },
	{ "set_anchor", "u", wlr_layer_shell_unstable_v1_types + 0 },
	{ "set_exclusive_zone", "i", wlr_layer_shell_unstable_v1_types + 0 },
	{ "set_margin", "iiii", wlr_layer_shell_unstable_v1_types + 0 },
	{ "set_keyboard_interactivity", "u", wlr_layer_shell_unstable_v1_types + 0 },
	{ "get_popup", "o", wlr_layer_shell_unstable_v1_types + 9 },
	{ "ack_configure", "u", wlr_layer_shell_unstable_v1_types + 0 },
	{ "destroy", "", wlr_layer_shell_unstable_v1_types + 0 },
	{ "set_layer", "2u", wlr_layer_shell_unstable_v1_types + 0 },
};

static const struct wl_message zwlr_layer_surface_v1_events[] = {
	{ "configure", "uuu", wlr_layer_shell_unstable_v1_types + 0 },
	{ "closed", "", wlr_layer_shell_unstable_v1_types + 0 },
};

WL_PRIVATE const struct wl_interface zwlr_layer_surface_v1_interface = {
	"zwlr_layer_surface_v1", 4,
	9, zwlr_layer_surface_v1_requests,
	2, zwlr_layer_surface_v1_events,
};

#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#if (__has_attribute(visibility) || defined(__GNUC__) && __GNUC__ >= 4)
#define WL_PRIVATE __attribute__ ((visibility("hidden")))
#else
#define WL_PRIVATE
#endif

extern const struct wl_interface wl_buffer_interface;
extern const struct wl_interface wl_output_interface;
extern const struct wl_interface zwlr_screencopy_frame_v1_interface;

static const struct wl_interface *wlr_screencopy_unstable_v1_types[] = {
	NULL,
	NULL,
	NULL,
	NULL,
	&zwlr_screencopy_frame_v1_interface,
	NULL,
	&wl_output_interface,
	&zwlr_screencopy_frame_v1_interface,
	NULL,
	&wl_output_interface,
	NULL,
	NULL,
	NULL,
	NULL,
	&wl_buffer_interface,
	&wl_buffer_interface,
};

static const struct wl_message zwlr_screencopy_manager_v1_requests[] = {
	{ "capture_output", "nio", wlr_screencopy_unstable_v1_types + 4 },
	{ "capture_output_region", "nioiiii", wlr_screencopy_unstable_v1_types + 7 },
	{ "destroy", "", wlr_screencopy_unstable_v1_types + 0 },
};

WL_PRIVATE const struct wl_interface zwlr_screencopy_manager_v1_interface = {
	"zwlr_screencopy_manager_v1", 3,
	3, zwlr_screencopy_manager_v1_requests,
	0, NULL,
};

static const struct wl_message zwlr_screencopy_frame_v1_requests[] = {
	{ "copy", "o", wlr_screencopy_unstable_v1_types + 14 },
	{ "destroy", "", wlr_screencopy_unstable_v1_types + 0 },
	{ "copy_with_damage", "2o", wlr_screencopy_unstable_v1_types + 15 },
};

static const struct wl_message zwlr_screencopy_frame_v1_events[] = {
	{ "buffer", "uuuu", wlr_screencopy_unstable_v1_types + 0 },
	{ "flags", "u", wlr_screencopy_unstable_v1_types + 0 },
	{ "ready", "uuu", wlr_screencopy_unstable_v1_types + 0 },
	{ "failed", "", wlr_screencopy_unstable_v1_types + 0 },
	{ "damage", "2uuuu", wlr_screencopy_unstable_v1_types + 0 },
	{ "linux_dmabuf", "3uuu", wlr_screencopy_unstable_v1_types + 0 },
	{ "buffer_done", "3", wlr_screencopy_unstable_v1_types + 0 },
};

WL_PRIVATE const struct wl_interface zwlr_screencopy_frame_v1_interface = {
	"zwlr_screencopy_frame_v1", 3,
	3, zwlr_screencopy_frame_v1_requests,
	7, zwlr_screencopy_frame_v1_events,
};

static void render_frame(void);
static void request_redraw(void);

struct shm_buffer {
    struct wl_buffer *wl_buffer;
    void *data;
    int width, height, stride;
    size_t size;
    cairo_surface_t *cairo_surface;
    bool busy;
};

static int create_shm_fd(size_t size)
{
    int fd = -1;
#if defined(__linux__)
    fd = syscall(SYS_memfd_create, "px-shm", 0);
#endif
    if (fd < 0) {
        char name[32];
        for (int i = 0; i < 100; i++) {
            snprintf(name, sizeof(name), "/px-wayland-%06x", rand() & 0xffffff);
            fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0600);
            if (fd >= 0) { shm_unlink(name); break; }
            if (errno != EEXIST) break;
        }
    }
    if (fd < 0) return -1;
    if (ftruncate(fd, (off_t)size) < 0) { close(fd); return -1; }
    return fd;
}

static struct shm_buffer *shm_buffer_create(struct wl_shm *shm, int w, int h, uint32_t format)
{
    int stride = w * 4;
    size_t size = (size_t)stride * (size_t)h;

    int fd = create_shm_fd(size);
    if (fd < 0) { perror("create_shm_fd"); return NULL; }

    void *data = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (data == MAP_FAILED) { perror("mmap"); close(fd); return NULL; }

    struct wl_shm_pool *pool = wl_shm_create_pool(shm, fd, (int32_t)size);
    struct wl_buffer *buffer = wl_shm_pool_create_buffer(pool, 0, w, h, stride, format);
    wl_shm_pool_destroy(pool);
    close(fd);

    struct shm_buffer *sb = calloc(1, sizeof(*sb));
    sb->wl_buffer = buffer;
    sb->data = data;
    sb->width = w;
    sb->height = h;
    sb->stride = stride;
    sb->size = size;
    return sb;
}

static void shm_buffer_destroy(struct shm_buffer *sb)
{
    if (!sb) return;
    if (sb->cairo_surface) cairo_surface_destroy(sb->cairo_surface);
    if (sb->wl_buffer) wl_buffer_destroy(sb->wl_buffer);
    if (sb->data) munmap(sb->data, sb->size);
    free(sb);
}

struct app {
    struct wl_display *display;
    struct wl_registry *registry;
    struct wl_compositor *compositor;
    struct wl_shm *shm;
    struct wl_seat *seat;
    struct wl_output *output;
    struct zwlr_layer_shell_v1 *layer_shell;
    struct zwlr_screencopy_manager_v1 *screencopy_mgr;

    struct wl_pointer *pointer;
    struct wl_keyboard *keyboard;

    struct xkb_context *xkb_ctx;
    struct xkb_keymap *xkb_keymap;
    struct xkb_state *xkb_state;

    struct shm_buffer *capture;
    bool capture_ready, capture_failed;
    uint32_t capture_format;

    struct wl_surface *surface;
    struct zwlr_layer_surface_v1 *layer_surface;
    struct wl_callback *frame_cb;
    bool configured;
    int32_t surf_width, surf_height;

    struct shm_buffer *draw_bufs[2];
    int cur_buf;

    double ptr_x, ptr_y;
    bool dirty;

    bool running, clicked;
    int click_x, click_y;

    bool rgb, view, coordinate;
};

static struct app A;

static void on_buffer_release(void *data, struct wl_buffer *wl_buffer)
{
    (void)wl_buffer;
    ((struct shm_buffer *)data)->busy = false;
    if (A.dirty && !A.frame_cb) render_frame();
}

static const struct wl_buffer_listener buffer_release_listener = {
    .release = on_buffer_release,
};

static const struct wl_seat_listener seat_listener;
static const struct wl_callback_listener frame_cb_listener;

static void registry_global(void *data, struct wl_registry *reg, uint32_t name,
                             const char *iface, uint32_t version)
{
    (void)data; (void)version;
    if (!strcmp(iface, wl_compositor_interface.name)) {
        A.compositor = wl_registry_bind(reg, name, &wl_compositor_interface, 4);
    } else if (!strcmp(iface, wl_shm_interface.name)) {
        A.shm = wl_registry_bind(reg, name, &wl_shm_interface, 1);
    } else if (!strcmp(iface, wl_seat_interface.name)) {
        A.seat = wl_registry_bind(reg, name, &wl_seat_interface, 5);
        wl_seat_add_listener(A.seat, &seat_listener, NULL);
    } else if (!strcmp(iface, wl_output_interface.name) && !A.output) {
        A.output = wl_registry_bind(reg, name, &wl_output_interface, 2);
    } else if (!strcmp(iface, zwlr_layer_shell_v1_interface.name)) {
        A.layer_shell = wl_registry_bind(reg, name, &zwlr_layer_shell_v1_interface, 1);
    } else if (!strcmp(iface, zwlr_screencopy_manager_v1_interface.name)) {
        A.screencopy_mgr = wl_registry_bind(reg, name, &zwlr_screencopy_manager_v1_interface, 1);
    }
}

static void registry_global_remove(void *d, struct wl_registry *r, uint32_t n)
{ (void)d; (void)r; (void)n; }

static const struct wl_registry_listener registry_listener = {
    .global = registry_global,
    .global_remove = registry_global_remove,
};

static void output_geometry(void *d, struct wl_output *o, int32_t x, int32_t y,
                             int32_t pw, int32_t ph, int32_t sub, const char *make,
                             const char *model, int32_t transform)
{ (void)d; (void)o; (void)x; (void)y; (void)pw; (void)ph; (void)sub; (void)make; (void)model; (void)transform; }

static void output_mode(void *d, struct wl_output *o, uint32_t flags,
                         int32_t w, int32_t h, int32_t refresh)
{
    (void)d; (void)o; (void)refresh;
    (void)w; (void)h; (void)flags;
}

static void output_done(void *d, struct wl_output *o) { (void)d; (void)o; }
static void output_scale(void *d, struct wl_output *o, int32_t f) { (void)d; (void)o; (void)f; }

static const struct wl_output_listener output_listener = {
    .geometry = output_geometry,
    .mode = output_mode,
    .done = output_done,
    .scale = output_scale,
};

static void frame_buffer(void *d, struct zwlr_screencopy_frame_v1 *frame,
                          uint32_t format, uint32_t w, uint32_t h, uint32_t stride)
{
    (void)d;
    size_t size = (size_t)stride * (size_t)h;
    int fd = create_shm_fd(size);
    if (fd < 0) { A.capture_failed = true; return; }

    void *map = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) { close(fd); A.capture_failed = true; return; }

    struct wl_shm_pool *pool = wl_shm_create_pool(A.shm, fd, (int32_t)size);
    struct wl_buffer *buffer = wl_shm_pool_create_buffer(pool, 0, (int32_t)w, (int32_t)h, (int32_t)stride, format);
    wl_shm_pool_destroy(pool);
    close(fd);

    struct shm_buffer *sb = calloc(1, sizeof(*sb));
    sb->wl_buffer = buffer;
    sb->data = map;
    sb->width = (int)w;
    sb->height = (int)h;
    sb->stride = (int)stride;
    sb->size = size;

    A.capture = sb;
    A.capture_format = format;
    zwlr_screencopy_frame_v1_copy(frame, buffer);
}

static void frame_flags(void *d, struct zwlr_screencopy_frame_v1 *f, uint32_t flags)
{ (void)d; (void)f; (void)flags; }

static void normalize_capture_format(void)
{
    if (!A.capture) return;
    if (A.capture_format != WL_SHM_FORMAT_XBGR8888 &&
        A.capture_format != WL_SHM_FORMAT_ABGR8888)
        return;

    uint8_t *base = (uint8_t *)A.capture->data;
    for (int y = 0; y < A.capture->height; y++) {
        uint8_t *row = base + (size_t)y * A.capture->stride;
        for (int x = 0; x < A.capture->width; x++) {
            uint8_t *px = row + (size_t)x * 4;
            uint8_t t = px[0];
            px[0] = px[2];
            px[2] = t;
        }
    }
    A.capture_format = (A.capture_format == WL_SHM_FORMAT_ABGR8888)
                        ? WL_SHM_FORMAT_ARGB8888 : WL_SHM_FORMAT_XRGB8888;
}

static void frame_ready(void *d, struct zwlr_screencopy_frame_v1 *frame,
                         uint32_t hi, uint32_t lo, uint32_t ns)
{
    (void)d; (void)hi; (void)lo; (void)ns;
    normalize_capture_format();
    A.capture_ready = true;
    zwlr_screencopy_frame_v1_destroy(frame);
}

static void frame_failed(void *d, struct zwlr_screencopy_frame_v1 *frame)
{
    (void)d;
    A.capture_failed = true;
    zwlr_screencopy_frame_v1_destroy(frame);
}

static const struct zwlr_screencopy_frame_v1_listener screencopy_listener = {
    .buffer = frame_buffer,
    .flags = frame_flags,
    .ready = frame_ready,
    .failed = frame_failed,
};

static void place_panel(int mx, int my, int sw, int sh, int w, int h,
                         bool right, bool bottom, int *ox, int *oy)
{
    *ox = right  ? mx + GAP : mx - GAP - w;
    *oy = bottom ? my + GAP : my - GAP - h;
    if (*ox < 0) *ox = 0;
    if (*oy < 0) *oy = 0;
    if (*ox + w > sw) *ox = sw - w;
    if (*oy + h > sh) *oy = sh - h;
}

static void sample_capture(int x, int y, int *r, int *g, int *b)
{
    if (!A.capture || x < 0 || y < 0 || x >= A.capture->width || y >= A.capture->height) {
        *r = *g = *b = 0;
        return;
    }
    uint8_t *row = (uint8_t *)A.capture->data + (size_t)y * A.capture->stride;
    uint32_t px;
    memcpy(&px, row + (size_t)x * 4, 4);
    *b = (px >> 0) & 0xff;
    *g = (px >> 8) & 0xff;
    *r = (px >> 16) & 0xff;
}

static cairo_surface_t *capture_as_cairo_surface(void)
{
    if (!A.capture) return NULL;
    cairo_format_t fmt = (A.capture_format == WL_SHM_FORMAT_ARGB8888)
                          ? CAIRO_FORMAT_ARGB32 : CAIRO_FORMAT_RGB24;
    return cairo_image_surface_create_for_data((unsigned char *)A.capture->data, fmt,
        A.capture->width, A.capture->height, A.capture->stride);
}

static void rounded_cell_path(cairo_t *cr, double x0, double y0, double x1, double y1,
                               double rtl, double rtr, double rbl, double rbr)
{
    cairo_new_path(cr);
    cairo_move_to(cr, x0 + rtl, y0);
    cairo_line_to(cr, x1 - rtr, y0);
    if (rtr > 0) cairo_arc(cr, x1 - rtr, y0 + rtr, rtr, -M_PI / 2, 0);
    else cairo_line_to(cr, x1, y0);
    cairo_line_to(cr, x1, y1 - rbr);
    if (rbr > 0) cairo_arc(cr, x1 - rbr, y1 - rbr, rbr, 0, M_PI / 2);
    else cairo_line_to(cr, x1, y1);
    cairo_line_to(cr, x0 + rbl, y1);
    if (rbl > 0) cairo_arc(cr, x0 + rbl, y1 - rbl, rbl, M_PI / 2, M_PI);
    else cairo_line_to(cr, x0, y1);
    cairo_line_to(cr, x0, y0 + rtl);
    if (rtl > 0) cairo_arc(cr, x0 + rtl, y0 + rtl, rtl, M_PI, 3 * M_PI / 2);
    else cairo_line_to(cr, x0, y0);
    cairo_close_path(cr);
}

static void draw_magnifier(cairo_t *cr, int panel_x, int panel_y, int mx, int my)
{
    int sw = A.capture ? A.capture->width  : A.surf_width;
    int sh = A.capture ? A.capture->height : A.surf_height;

    int sx = mx - HALF, sy = my - HALF;
    if (sx < 0) sx = 0;
    if (sy < 0) sy = 0;
    if (sx + GRID_CELLS > sw) sx = sw - GRID_CELLS;
    if (sy + GRID_CELLS > sh) sy = sh - GRID_CELLS;

    cairo_save(cr);
    cairo_translate(cr, panel_x, panel_y);

    for (int row = 0; row < GRID_CELLS; row++) {
        for (int col = 0; col < GRID_CELLS; col++) {
            int r, g, b;
            sample_capture(sx + col, sy + row, &r, &g, &b);
            double cx = col * CELL_PX, cy = row * CELL_PX;
            bool top = row == 0, bot = row == GRID_CELLS - 1;
            bool left = col == 0, right = col == GRID_CELLS - 1;

            cairo_set_source_rgb(cr, r / 255.0, g / 255.0, b / 255.0);
            if (CORNER_R > 0 && (top || bot) && (left || right)) {
                rounded_cell_path(cr, cx, cy, cx + CELL_PX, cy + CELL_PX,
                    (top && left) ? CORNER_R : 0, (top && right) ? CORNER_R : 0,
                    (bot && left) ? CORNER_R : 0, (bot && right) ? CORNER_R : 0);
                cairo_fill(cr);
            } else {
                cairo_rectangle(cr, cx, cy, CELL_PX, CELL_PX);
                cairo_fill(cr);
            }

            cairo_set_source_rgb(cr, 0, 0, 0);
            cairo_set_line_width(cr, 1);
            if (col < GRID_CELLS - 1) {
                cairo_move_to(cr, cx + CELL_PX - 0.5, cy);
                cairo_line_to(cr, cx + CELL_PX - 0.5, cy + CELL_PX);
                cairo_stroke(cr);
            }
            if (row < GRID_CELLS - 1) {
                cairo_move_to(cr, cx, cy + CELL_PX - 0.5);
                cairo_line_to(cr, cx + CELL_PX, cy + CELL_PX - 0.5);
                cairo_stroke(cr);
            }
        }
    }

    double ccx = HALF * CELL_PX, ccy = HALF * CELL_PX;
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_rectangle(cr, ccx + 0.5, ccy + 0.5, CELL_PX - 1, CELL_PX - 1);
    cairo_stroke(cr);

    cairo_set_source_rgb(cr, 0x44 / 255.0, 0x44 / 255.0, 0x44 / 255.0);
    cairo_rectangle(cr, 0.5, 0.5, WIN_SIZE - 1, WIN_SIZE - 1);
    cairo_stroke(cr);

    cairo_restore(cr);
}

static void draw_swatch(cairo_t *cr, int panel_x, int panel_y, int r, int g, int b)
{
    cairo_save(cr);
    cairo_translate(cr, panel_x, panel_y);

    cairo_set_source_rgb(cr, 0x1a / 255.0, 0x1a / 255.0, 0x1a / 255.0);
    cairo_rectangle(cr, 0, 0, SW_W, SW_H);
    cairo_fill(cr);

    cairo_set_source_rgb(cr, r / 255.0, g / 255.0, b / 255.0);
    cairo_rectangle(cr, 0, 0, SW_W / 3.0, SW_H);
    cairo_fill(cr);

    cairo_set_source_rgb(cr, 0x44 / 255.0, 0x44 / 255.0, 0x44 / 255.0);
    cairo_move_to(cr, SW_W / 3.0, 0);
    cairo_line_to(cr, SW_W / 3.0, SW_H);
    cairo_stroke(cr);

    char hex[12], rgb_str[24];
    snprintf(hex, sizeof(hex), "#%02x%02x%02x", r, g, b);
    snprintf(rgb_str, sizeof(rgb_str), "%d %d %d", r, g, b);

    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_select_font_face(cr, "monospace", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 13);
    cairo_move_to(cr, SW_W / 3.0 + 7, 22);
    cairo_show_text(cr, hex);
    cairo_move_to(cr, SW_W / 3.0 + 7, 40);
    cairo_show_text(cr, rgb_str);

    cairo_set_source_rgb(cr, 0x44 / 255.0, 0x44 / 255.0, 0x44 / 255.0);
    cairo_rectangle(cr, 0.5, 0.5, SW_W - 1, SW_H - 1);
    cairo_stroke(cr);

    cairo_restore(cr);
}

static void on_frame_done(void *data, struct wl_callback *cb, uint32_t time)
{
    (void)data; (void)time;
    wl_callback_destroy(cb);
    A.frame_cb = NULL;
    if (A.dirty) render_frame();
}

static const struct wl_callback_listener frame_cb_listener = {
    .done = on_frame_done,
};

static void request_redraw(void)
{
    A.dirty = true;
    if (A.frame_cb) return;
    render_frame();
}

static void render_frame(void)
{
    if (!A.configured || A.surf_width <= 0 || A.surf_height <= 0) return;

    struct shm_buffer *buf = A.draw_bufs[A.cur_buf];
    if (!buf || buf->busy) return;
    A.dirty = false;

    cairo_t *cr = cairo_create(buf->cairo_surface);

    cairo_surface_t *bg = capture_as_cairo_surface();
    if (bg) {
        cairo_set_source_surface(cr, bg, 0, 0);
        cairo_paint(cr);
        cairo_surface_destroy(bg);
    } else {
        cairo_set_source_rgb(cr, 0, 0, 0);
        cairo_paint(cr);
    }

    int mx = (int)A.ptr_x, my = (int)A.ptr_y;
    int sw = A.surf_width, sh = A.surf_height;

    bool prev_right  = mx + GAP + WIN_SIZE <= sw;
    bool prev_bottom = my + GAP + WIN_SIZE <= sh;

    int px, py, swx, swy;
    place_panel(mx, my, sw, sh, WIN_SIZE, WIN_SIZE, prev_right, prev_bottom, &px, &py);
    place_panel(mx, my, sw, sh, SW_W, SW_H, !prev_right, prev_bottom, &swx, &swy);

    draw_magnifier(cr, px, py, mx, my);

    int r, g, b;
    sample_capture(mx, my, &r, &g, &b);
    draw_swatch(cr, swx, swy, r, g, b);

    cairo_destroy(cr);

    buf->busy = true;
    wl_surface_attach(A.surface, buf->wl_buffer, 0, 0);
    wl_surface_damage_buffer(A.surface, 0, 0, A.surf_width, A.surf_height);

    A.frame_cb = wl_surface_frame(A.surface);
    wl_callback_add_listener(A.frame_cb, &frame_cb_listener, NULL);

    wl_surface_commit(A.surface);
    A.cur_buf ^= 1;
}

static void ensure_draw_buffers(int w, int h)
{
    for (int i = 0; i < 2; i++) {
        if (A.draw_bufs[i]) shm_buffer_destroy(A.draw_bufs[i]);
        A.draw_bufs[i] = shm_buffer_create(A.shm, w, h, WL_SHM_FORMAT_ARGB8888);
        A.draw_bufs[i]->cairo_surface = cairo_image_surface_create_for_data(
            (unsigned char *)A.draw_bufs[i]->data, CAIRO_FORMAT_ARGB32, w, h, A.draw_bufs[i]->stride);
        wl_buffer_add_listener(A.draw_bufs[i]->wl_buffer, &buffer_release_listener, A.draw_bufs[i]);
    }
}

static void layer_surface_configure(void *d, struct zwlr_layer_surface_v1 *surf,
                                     uint32_t serial, uint32_t w, uint32_t h)
{
    (void)d;
    A.surf_width = (int32_t)w;
    A.surf_height = (int32_t)h;
    zwlr_layer_surface_v1_ack_configure(surf, serial);
    ensure_draw_buffers(A.surf_width, A.surf_height);
    A.configured = true;
    request_redraw();
}

static void layer_surface_closed(void *d, struct zwlr_layer_surface_v1 *s)
{ (void)d; (void)s; A.running = false; }

static const struct zwlr_layer_surface_v1_listener layer_surface_listener = {
    .configure = layer_surface_configure,
    .closed = layer_surface_closed,
};

static void pointer_enter(void *d, struct wl_pointer *p, uint32_t s,
                           struct wl_surface *surf, wl_fixed_t sx, wl_fixed_t sy)
{
    (void)d; (void)p; (void)s; (void)surf;
    A.ptr_x = wl_fixed_to_double(sx);
    A.ptr_y = wl_fixed_to_double(sy);
    request_redraw();
}

static void pointer_leave(void *d, struct wl_pointer *p, uint32_t s, struct wl_surface *surf)
{ (void)d; (void)p; (void)s; (void)surf; }

static void pointer_motion(void *d, struct wl_pointer *p, uint32_t t, wl_fixed_t sx, wl_fixed_t sy)
{
    (void)d; (void)p; (void)t;
    A.ptr_x = wl_fixed_to_double(sx);
    A.ptr_y = wl_fixed_to_double(sy);
    request_redraw();
}

static void pointer_button(void *d, struct wl_pointer *p, uint32_t s, uint32_t t,
                            uint32_t button, uint32_t state)
{
    (void)d; (void)p; (void)s; (void)t;
    if (button == BTN_LEFT && state == WL_POINTER_BUTTON_STATE_PRESSED) {
        A.clicked = true;
        A.click_x = (int)A.ptr_x;
        A.click_y = (int)A.ptr_y;
        A.running = false;
    }
}

static void pointer_axis(void *d, struct wl_pointer *p, uint32_t t, uint32_t a, wl_fixed_t v)
{ (void)d; (void)p; (void)t; (void)a; (void)v; }
static void pointer_frame(void *d, struct wl_pointer *p) { (void)d; (void)p; }
static void pointer_axis_source(void *d, struct wl_pointer *p, uint32_t s) { (void)d; (void)p; (void)s; }
static void pointer_axis_stop(void *d, struct wl_pointer *p, uint32_t t, uint32_t a) { (void)d; (void)p; (void)t; (void)a; }
static void pointer_axis_discrete(void *d, struct wl_pointer *p, uint32_t a, int32_t v) { (void)d; (void)p; (void)a; (void)v; }

static const struct wl_pointer_listener pointer_listener = {
    .enter = pointer_enter,
    .leave = pointer_leave,
    .motion = pointer_motion,
    .button = pointer_button,
    .axis = pointer_axis,
    .frame = pointer_frame,
    .axis_source = pointer_axis_source,
    .axis_stop = pointer_axis_stop,
    .axis_discrete = pointer_axis_discrete,
};

static void keyboard_keymap(void *d, struct wl_keyboard *kb, uint32_t format, int32_t fd, uint32_t size)
{
    (void)d; (void)kb;
    if (format != WL_KEYBOARD_KEYMAP_FORMAT_XKB_V1) { close(fd); return; }
    char *map = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (map == MAP_FAILED) { close(fd); return; }
    if (A.xkb_keymap) xkb_keymap_unref(A.xkb_keymap);
    A.xkb_keymap = xkb_keymap_new_from_string(A.xkb_ctx, map, XKB_KEYMAP_FORMAT_TEXT_V1, XKB_KEYMAP_COMPILE_NO_FLAGS);
    munmap(map, size);
    close(fd);
    if (A.xkb_state) xkb_state_unref(A.xkb_state);
    A.xkb_state = xkb_state_new(A.xkb_keymap);
}

static void keyboard_enter(void *d, struct wl_keyboard *kb, uint32_t s, struct wl_surface *surf, struct wl_array *keys)
{ (void)d; (void)kb; (void)s; (void)surf; (void)keys; }
static void keyboard_leave(void *d, struct wl_keyboard *kb, uint32_t s, struct wl_surface *surf)
{ (void)d; (void)kb; (void)s; (void)surf; }

static void keyboard_key(void *d, struct wl_keyboard *kb, uint32_t s, uint32_t t, uint32_t key, uint32_t state)
{
    (void)d; (void)kb; (void)s; (void)t; (void)key;
    if (state == WL_KEYBOARD_KEY_STATE_PRESSED) A.running = false;
}

static void keyboard_modifiers(void *d, struct wl_keyboard *kb, uint32_t s,
                                uint32_t depressed, uint32_t latched, uint32_t locked, uint32_t group)
{
    (void)d; (void)kb; (void)s;
    if (A.xkb_state) xkb_state_update_mask(A.xkb_state, depressed, latched, locked, 0, 0, group);
}

static void keyboard_repeat_info(void *d, struct wl_keyboard *kb, int32_t rate, int32_t delay)
{ (void)d; (void)kb; (void)rate; (void)delay; }

static const struct wl_keyboard_listener keyboard_listener = {
    .keymap = keyboard_keymap,
    .enter = keyboard_enter,
    .leave = keyboard_leave,
    .key = keyboard_key,
    .modifiers = keyboard_modifiers,
    .repeat_info = keyboard_repeat_info,
};

static void seat_capabilities(void *d, struct wl_seat *seat, uint32_t caps)
{
    (void)d;
    if ((caps & WL_SEAT_CAPABILITY_POINTER) && !A.pointer) {
        A.pointer = wl_seat_get_pointer(seat);
        wl_pointer_add_listener(A.pointer, &pointer_listener, NULL);
    }
    if ((caps & WL_SEAT_CAPABILITY_KEYBOARD) && !A.keyboard) {
        A.keyboard = wl_seat_get_keyboard(seat);
        wl_keyboard_add_listener(A.keyboard, &keyboard_listener, NULL);
    }
}

static void seat_name(void *d, struct wl_seat *s, const char *n) { (void)d; (void)s; (void)n; }

static const struct wl_seat_listener seat_listener = {
    .capabilities = seat_capabilities,
    .name = seat_name,
};

static void copy_to_clipboard(const char *text)
{
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "printf '%s' | wl-copy", text);
    if (system(cmd) != 0) fprintf(stderr, "px: wl-copy failed (is wl-clipboard installed?)\n");
}

static void print_usage(void)
{
    printf("Usage: px [-h] [-xrvca] [-t seconds]\n\n"
           "Click left mouse button to pick a color. Any key exits.\n\n"
           "Options:\n"
           "  -h        display this message and exit\n"
           "  -x        print in hexadecimal only (default)\n"
           "  -r        print in rgb\n"
           "  -v        show color swatch in terminal\n"
           "  -c        print coordinate\n"
           "  -a        run px with the -xvc options\n"
           "  -t <n>    sleep for n seconds\n\n"
           "Requires a wlroots-based compositor "
           "(wlr-layer-shell-unstable-v1 + wlr-screencopy-unstable-v1).\n");
}

int main(int argc, char **argv)
{
    int c;
    memset(&A, 0, sizeof(A));

    while ((c = getopt(argc, argv, "hxrvcat:")) != -1) {
        switch (c) {
            case 'h': print_usage(); return 0;
            case 'x': A.rgb = false; break;
            case 'r': A.rgb = true; break;
            case 'v': A.view = true; break;
            case 'c': A.coordinate = true; break;
            case 'a': A.rgb = false; A.view = true; A.coordinate = true; break;
            case 't': sleep((unsigned)atoi(optarg)); break;
            default: print_usage(); return 1;
        }
    }

    A.display = wl_display_connect(NULL);
    if (!A.display) {
        fprintf(stderr, "px: cannot connect to a Wayland display\n");
        return 1;
    }

    srand((unsigned)time(NULL) ^ (unsigned)getpid());
    A.xkb_ctx = xkb_context_new(XKB_CONTEXT_NO_FLAGS);

    A.registry = wl_display_get_registry(A.display);
    wl_registry_add_listener(A.registry, &registry_listener, NULL);
    wl_display_roundtrip(A.display);

    if (!A.compositor || !A.shm || !A.seat || !A.output) {
        fprintf(stderr, "px: missing a required Wayland global (compositor/shm/seat/output)\n");
        return 1;
    }
    if (!A.layer_shell || !A.screencopy_mgr) {
        fprintf(stderr, "px: compositor needs wlr-layer-shell-unstable-v1 and "
                        "wlr-screencopy-unstable-v1 (Sway, Hyprland, river, ...)\n");
        return 1;
    }

    wl_output_add_listener(A.output, &output_listener, NULL);
    wl_display_roundtrip(A.display);

    struct zwlr_screencopy_frame_v1 *frame =
        zwlr_screencopy_manager_v1_capture_output(A.screencopy_mgr, 0, A.output);
    zwlr_screencopy_frame_v1_add_listener(frame, &screencopy_listener, NULL);

    while (!A.capture_ready && !A.capture_failed) {
        if (wl_display_dispatch(A.display) < 0) {
            fprintf(stderr, "px: connection error while waiting for screencopy\n");
            return 1;
        }
    }
    if (A.capture_failed || !A.capture) {
        fprintf(stderr, "px: screencopy capture failed\n");
        return 1;
    }

    A.surface = wl_compositor_create_surface(A.compositor);
    A.layer_surface = zwlr_layer_shell_v1_get_layer_surface(
        A.layer_shell, A.surface, A.output, ZWLR_LAYER_SHELL_V1_LAYER_OVERLAY, "px");

    zwlr_layer_surface_v1_set_anchor(A.layer_surface,
        ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP | ZWLR_LAYER_SURFACE_V1_ANCHOR_BOTTOM |
        ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT | ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT);
    zwlr_layer_surface_v1_set_size(A.layer_surface, A.capture->width, A.capture->height);
    zwlr_layer_surface_v1_set_exclusive_zone(A.layer_surface, -1);
    zwlr_layer_surface_v1_set_keyboard_interactivity(
        A.layer_surface, ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_EXCLUSIVE);
    zwlr_layer_surface_v1_add_listener(A.layer_surface, &layer_surface_listener, NULL);

    wl_surface_commit(A.surface);

    A.running = true;
    while (A.running) {
        if (wl_display_dispatch(A.display) < 0) break;
    }

    if (A.clicked) {
        int r, g, b;
        sample_capture(A.click_x, A.click_y, &r, &g, &b);
        uint32_t color = ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;

        char out[128];
        if (A.rgb) snprintf(out, sizeof(out), "%d, %d, %d", r, g, b);
        else snprintf(out, sizeof(out), "#%06x", color);

        copy_to_clipboard(out);
        printf("%s", out);
        if (A.view) printf("  \033[48;2;%d;%d;%dm      \033[0m", r, g, b);
        if (A.coordinate) printf("  (%dx%d)", A.click_x, A.click_y);
        putchar('\n');
    }

    if (A.frame_cb) wl_callback_destroy(A.frame_cb);
    if (A.layer_surface) zwlr_layer_surface_v1_destroy(A.layer_surface);
    if (A.surface) wl_surface_destroy(A.surface);
    for (int i = 0; i < 2; i++) shm_buffer_destroy(A.draw_bufs[i]);
    shm_buffer_destroy(A.capture);
    if (A.xkb_state) xkb_state_unref(A.xkb_state);
    if (A.xkb_keymap) xkb_keymap_unref(A.xkb_keymap);
    if (A.xkb_ctx) xkb_context_unref(A.xkb_ctx);
    wl_display_disconnect(A.display);

    return A.clicked ? 0 : 1;
}
