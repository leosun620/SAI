
#if !defined (__SAITELEMETRY_H_)
#define __SAITELEMETRY_H_

#include <saitypes.h>

/**
 * @brief Telemetry feature types
 * INT_EP, INT_TRANSIT, POSTCARD are mutually exclusive
 * MOD can coexist with any one of the three above
 */
typedef enum _sai_telemetry_type_t {
    /** INT source and sink */
    SAI_TELEMETRY_TYPE_INT_EP,
    /** INT transit */
    SAI_TELEMETRY_TYPE_INT_TRANSIT,
    /** Postcard */
    SAI_TELEMETRY_TYPE_POSTCARD,
    /** Mirror on Drop */
    SAI_TELEMETRY_TYPE_MOD,
} sai_telemetry_type_t;

/**
 * @brief Telemetry attributes
 */
typedef enum _sai_telemetry_attr_t {
    /** List of telemetry features to enable */
    SAI_TELEMETRY_ATTR_TYPE_LIST,
    /** Globally unique switch ID */
    SAI_TELEMETRY_ATTR_SWITCH_ID,
    /** List of ERSPAN mirror sessions for sending reports */
    SAI_TELEMETRY_ATTR_MIRROR_LIST,

    /** INT sink downstream ports */
    SAI_TELEMETRY_ATTR_INT_SINK_PORT_LIST,
    /** Reserved DSCP value for INT over L4 */
    SAI_TELEMETRY_ATTR_INT_DSCP,
} sai_telemetry_attr_t;

/** Queue alert report trigger attributes */
typedef enum _sai_telemetry_queue_alert_attr_t {
    /** egress port */
    SAI_TELEMETRY_QUEUE_ALERT_ATTR_EGRESS_PORT,
    /** queue id */
    SAI_TELEMETRY_QUEUE_ALERT_ATTR_QUEUE_ID,
    /** queue depth threshold */
    SAI_TELEMETRY_QUEUE_ALERT_ATTR_QUEUE_DEPTH_THRESHOLD,
    /** queue latency threshold */
    SAI_TELEMETRY_QUEUE_ALERT_ATTR_QUEUE_LATENCY_THRESHOLD,
} sai_telemetry_queue_alert_attr_t;

/** Flow alert report trigger attributes */
typedef enum _sai_telemetry_flow_alert_attr_t {
    /** Flow state clear cycle */
    SAI_TELEMETRY_FLOW_ALERT_ATTR_FLOW_STATE_CLEAR_CYCLE,
    /** Latency sensitivity for flow state change detection */
    SAI_TELEMETRY_FLOW_ALERT_ATTR_LATENCY_SENSITIVITY,
} sai_telemetry_flow_alert_attr_t;

/** INT instructions */
typedef enum _sai_telemetry_int_instruction_t {
    /** Switch ID */
    SAI_TELEMETRY_INT_INST_SWITCH_ID,
    /** Ingress and egress ports */
    SAI_TELEMETRY_INT_INST_SWITCH_PORTS,
    /** Timestamp at ingress */
    SAI_TELEMETRY_INT_INST_INGRESS_TIMESTAMP,
    /** Timestamp at egress */
    SAI_TELEMETRY_INT_INST_EGRESS_TIMESTAMP,
    /** Queue ID and queue depth */
    SAI_TELEMETRY_INT_INST_QUEUE_INFO,
} sai_telemetry_int_instruction_t;

/** INT config session for endpoint switch */
typedef enum _sai_telemetry_int_session_attr_t {
    /** INT config session ID */
    SAI_TELEMETRY_INT_SESSION_ATTR_SESSION_ID,
    /** INT max hop count */
    SAI_TELEMETRY_INT_SESSION_ATTR_MAX_HOP_COUNT,
    /** INT instruction list*/
    SAI_TELEMETRY_INT_SESSION_ATTR_INT_INST_LIST,
} sai_telemetry_int_session_attr_t;

typedef sai_status_t (*sai_create_telemetry_fn)(
        _Out_ sai_object_id_t *telemetry_obj,
        _In_  uint32_t attr_count,
        _In_  const sai_attribute_t *attr_list);

typedef sai_status_t (*sai_remove_telemetry_fn)(
        _In_ sai_object_id_t telemetry_obj);

typedef sai_status_t (*sai_get_telemetry_attribute_fn)(
        _In_    sai_object_id_t telemetry_obj,
        _In_    uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

typedef sai_status_t (*sai_set_telemetry_attribute_fn)(
        _In_  sai_object_id_t telemetry_obj,
        _In_  const sai_attribute_t *attr);

typedef sai_status_t (*sai_create_telemetry_watchlist_entry_fn)(
        _Out_ sai_object_id_t *telemetry_watchlist_entry_id,
        _In_  uint32_t attr_count,
        _In_  const sai_attribute_t *attr_list);

typedef sai_status_t (*sai_remove_telemetry_watchlist_entry_fn)(
        _In_ sai_object_id_t telemetry_watchlist_entry_id);

typedef sai_status_t (*sai_get_telemetry_watchlist_entry_attribute_fn)(
        _In_    sai_object_id_t telemetry_watchlist_entry_id,
        _In_    uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

typedef sai_status_t (*sai_set_telemetry_watchlist_entry_attribute_fn)(
        _In_  sai_object_id_t telemetry_watchlist_entry_id,
        _In_  const sai_attribute_t *attr);

typedef sai_status_t (*sai_create_telemetry_queue_alert_fn)(
        _Out_ sai_object_id_t *telemetry_queue_alert_id,
        _In_  uint32_t attr_count,
        _In_  const sai_attribute_t *attr_list);

typedef sai_status_t (*sai_remove_telemetry_queue_alert_fn)(
        _In_ sai_object_id_t telemetry_queue_alert_id);

typedef sai_status_t (*sai_get_telemetry_queue_alert_attribute_fn)(
        _In_    sai_object_id_t telemetry_queue_alert_id,
        _In_    uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

typedef sai_status_t (*sai_set_telemetry_queue_alert_attribute_fn)(
        _In_  sai_object_id_t telemetry_queue_alert_id,
        _In_  const sai_attribute_t *attr);

typedef sai_status_t (*sai_create_telemetry_flow_alert_fn)(
        _Out_ sai_object_id_t *telemetry_flow_alert_id,
        _In_  uint32_t attr_count,
        _In_  const sai_attribute_t *attr_list);

typedef sai_status_t (*sai_remove_telemetry_flow_alert_fn)(
        _In_ sai_object_id_t telemetry_flow_alert_id);

typedef sai_status_t (*sai_get_telemetry_flow_alert_attribute_fn)(
        _In_    sai_object_id_t telemetry_flow_alert_id,
        _In_    uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

typedef sai_status_t (*sai_set_telemetry_flow_alert_attribute_fn)(
        _In_  sai_object_id_t telemetry_flow_alert_id,
        _In_  const sai_attribute_t *attr);

typedef sai_status_t (*sai_create_telemetry_int_session_fn)(
        _Out_ sai_object_id_t *telemetry_int_session_id,
        _In_  uint32_t attr_count,
        _In_  const sai_attribute_t *attr_list);

typedef sai_status_t (*sai_remove_telemetry_int_session_fn)(
        _In_ sai_object_id_t telemetry_int_session_id);

typedef sai_status_t (*sai_get_telemetry_int_session_attribute_fn)(
        _In_    sai_object_id_t telemetry_int_session_id,
        _In_    uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

typedef sai_status_t (*sai_set_telemetry_int_session_attribute_fn)(
        _In_  sai_object_id_t telemetry_int_session_id,
        _In_  const sai_attribute_t *attr);

typedef sai_status_t (*sai_create_telemetry_int_sink_port_fn)(
        _Out_ sai_object_id_t *telemetry_int_sink_port_id,
        _In_  uint32_t attr_count,
        _In_  const sai_attribute_t *attr_list);

typedef sai_status_t (*sai_remove_telemetry_int_sink_port_fn)(
        _In_ sai_object_id_t telemetry_int_sink_port_id);

typedef sai_status_t (*sai_get_telemetry_int_sink_port_attribute_fn)(
        _In_    sai_object_id_t telemetry_int_sink_port_id,
        _In_    uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

typedef sai_status_t (*sai_set_telemetry_int_sink_port_attribute_fn)(
        _In_ sai_object_id_t telemetry_int_sink_port_id,
        _In_ const sai_attribute_t *attr);

typedef struct _sai_telemetry_api_t {
    sai_create_telemetry_fn                       create_telemetry;
    sai_remove_telemetry_fn                       remove_telemetry;
    sai_get_telemetry_attribute_fn                get_telemetry_attribute;
    sai_set_telemetry_attribute_fn                set_telemetry_attribute;

    sai_create_telemetry_queue_alert_fn           create_telemetry_queue_alert;
    sai_remove_telemetry_queue_alert_fn           remove_telemetry_queue_alert;
    sai_get_telemetry_queue_alert_attribute_fn    get_telemetry_queue_alert_attribute;
    sai_set_telemetry_queue_alert_attribute_fn    set_telemetry_queue_alert_attribute;

    sai_create_telemetry_flow_alert_fn            create_telemetry_flow_alert;
    sai_remove_telemetry_flow_alert_fn            remove_telemetry_flow_alert;
    sai_get_telemetry_flow_alert_attribute_fn     get_telemetry_flow_alert_attribute;
    sai_set_telemetry_flow_alert_attribute_fn     set_telemetry_flow_alert_attribute;

    sai_create_telemetry_int_session_fn           create_telemetry_int_session;
    sai_remove_telemetry_int_session_fn           remove_telemetry_int_session;
    sai_get_telemetry_int_session_attribute_fn    get_telemetry_int_session_attribute;
    sai_set_telemetry_int_session_attribute_fn    set_telemetry_int_session_attribute;

    sai_create_telemetry_int_sink_port_fn         create_telemetry_int_sink_port;
    sai_remove_telemetry_int_sink_port_fn         remove_telemetry_int_sink_port;
    sai_get_telemetry_int_sink_port_attribute_fn  get_telemetry_int_sink_port_attribute;
    sai_set_telemetry_int_sink_port_attribute_fn  set_telemetry_int_sink_port_attribute;
} sai_telemetry_api_t;

/**
 * @}
 */
#endif /** __SAITELEMETRY_H_ */
