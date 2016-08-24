<?php

function product_manager_admin_settings() {
  $types = node_type_get_types();
  foreach($types as $node_type) {
    $options[$node_type->type] = $node_type->name;
    $fields[$node_type->name] = field_info_instances('node', $node_type->name);
  }
  dpm($fields[$node_type->name]);
  $form['node_types'] = array(
    '#type' => 'select',
    '#title' => t('Select Content Type'),
    '#options' => $options,
    '#default_value' => variable_get('product_manager_node_types', array('page')),
    '#description' => t('A text field will be available on these content types to
    make user-specific notes.'),
  );
  
  $form['image_field'] = array(
    '#type' => 'fieldset',
    '#states' => array(
      'visible' => array(
        // action to take.
        ':input[name="node_types"]' => array('value' => t('product')),
      ),
    ),
  );
  
  
  $form['image_field']['image'] = array(
    '#type' => 'select',
    '#title' => t('Select Image'),
    '#options' => $options,
    '#default_value' => variable_get('product_manager_node_types', array('page')),
    '#states' => array(
      'visible' => array(
        // action to take.
        ':input[name="node_types"]' => array('value' => t('product')),
      ),
    ),
  );
  
  $form['#submit'][] = 'product_manager_admin_settings_submit';
  return system_settings_form($form);
}

/**
* Process annotation settings submission.
*/
function product_manager_admin_settings_submit($form, $form_state) {
  // Loop through each of the content type checkboxes shown on the form.
  foreach ($form_state['values']['product_manager_node_types'] as $key => $value) {
    // If the check box for a content type is unchecked, look to see whether
    // this content type has the annotation field attached to it using the
    // field_info_instance function. If it does then we need to remove the
    // annotation field as the administrator has unchecked the box.
    if (!$value) {
      $instance = field_info_instance('node', 'product_manager', $key);
      if (!empty($instance)) {
        field_delete_instance($instance);
        watchdog("Annotation", 'Deleted annotation field from content type:
        %key', array('%key' => $key));
      }
    } else {
      // If the check box for a content type is checked, look to see whether
      // the field is associated with that content type. If not then add the
      // annotation field to the content type.
      $instance = field_info_instance('node', 'product_manager', $key);
      if (empty($instance)) {
        $instance = array(
        'field_name' => 'product_manager',
        'entity_type' => 'node',
        'bundle' => $key,
        'label' => t('Annotation'),
        'widget_type' => 'text_textarea_with_summary',
        'settings' => array('display_summary' => TRUE),
        'display' => array(
        'default' => array(
        'type' => 'text_default',
        ),
        'teaser' => array(
        'type' => 'text_summary_or_trimmed',
        ),
        ),
        );
        $instance = field_create_instance($instance);
        watchdog('Annotation', 'Added annotation field to content type: %key',
        array('%key' => $key));
      }
    }
  } // End foreach loop.
}

/**
* Validate annotation settings submission.
*/
function annotate_admin_settings_validate($form, &$form_state) {
  $limit = $form_state['values']['annotate_limit_per_node'];
  if (!is_numeric($limit)) {
    form_set_error('annotate_limit_per_node', t('Please enter number.'));
  }
}
