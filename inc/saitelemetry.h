
#if !defined (__SAITELEMETRY_H_)
#define __SAITELEMETRY_H_

#include <saitypes.h>

/**
 * @brief Queue alert report trigger attributes
 */
typedef enum _sai_telemetry_queue_alert_attr_t {
    /**
     * @brief egress port
     *
     * @type sai_object_id_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_TELEMETRY_QUEUE_ALERT_ATTR_EGRESS_PORT,

    /**
     * @brief queue index
     *
     * @type sai_uint8_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_TELEMETRY_QUEUE_ALERT_ATTR_QUEUE_ID,

    /**
     * @brief queue depth threshold
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_TELEMETRY_QUEUE_ALERT_ATTR_QUEUE_DEPTH_THRESHOLD,

    /**
     * @brief queue latency threshold
     *
     * @type sai_uint32_t
     * @flags CREATE_AND_SET
     */
    SAI_TELEMETRY_QUEUE_ALERT_ATTR_QUEUE_LATENCY_THRESHOLD

} sai_telemetry_queue_alert_attr_t;

/**
 * @brief INT config session attributes
 */
typedef enum _sai_telemetry_int_session_attr_t {
    /**
     * @brief INT config session ID
     *
     * @type sai_uint16_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_TELEMETRY_INT_SESSION_ATTR_SESSION_ID,

    /**
     * @brief INT max hop count
     *
     * @type sai_uint8_t
     * @flags CREATE_AND_SET
     */
    SAI_TELEMETRY_INT_SESSION_ATTR_MAX_HOP_COUNT,

    /**
     * @brief add switch ID in INT instruction
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_TELEMETRY_INT_SESSION_ATTR_INST_SWITCH_ID,

    /**
     * @brief add ingress and egress ports in INT instruction
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_TELEMETRY_INT_SESSION_ATTR_INST_SWITCH_PORTS,

    /**
     * @brief add ingress Timestamp in INT instruction
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_TELEMETRY_INT_SESSION_ATTR_INST_INGRESS_TIMESTAMP,

    /**
     * @brief add egress Timestamp in INT instruction
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_TELEMETRY_INT_SESSION_ATTR_INST_EGRESS_TIMESTAMP,

    /**
     * @brief add queue information in INT instruction
     *
     * @type bool
     * @flags CREATE_AND_SET
     */
    SAI_TELEMETRY_INT_SESSION_ATTR_INST_QUEUE_INFO

} sai_telemetry_int_session_attr_t;

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

typedef struct _sai_telemetry_api_t {
    sai_create_telemetry_queue_alert_fn           create_telemetry_queue_alert;
    sai_remove_telemetry_queue_alert_fn           remove_telemetry_queue_alert;
    sai_get_telemetry_queue_alert_attribute_fn    get_telemetry_queue_alert_attribute;
    sai_set_telemetry_queue_alert_attribute_fn    set_telemetry_queue_alert_attribute;

    sai_create_telemetry_int_session_fn           create_telemetry_int_session;
    sai_remove_telemetry_int_session_fn           remove_telemetry_int_session;
    sai_get_telemetry_int_session_attribute_fn    get_telemetry_int_session_attribute;
    sai_set_telemetry_int_session_attribute_fn    set_telemetry_int_session_attribute;
} sai_telemetry_api_t;

/**
 * @}
 */
#endif /** __SAITELEMETRY_H_ */
