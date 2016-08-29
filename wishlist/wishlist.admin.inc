<?php


function wishlist_settings_form($form, &$form_state) {
  $entity_info = entity_get_info('node');
  
  $default_value = variable_get('wishlist_settings');
  
  $bundles = [];
    foreach ($entity_info['bundles'] as $key => $value) {
    $bundles[$key] = $value['label'];
  }
  
  $first_bundle = array_keys($bundles);
  $first_bundle = reset($first_bundle);
  
  $form_state['storage']['bundle'] =
    isset($form_state['storage']['bundle'])
    ? $form_state['storage']['bundle'] :
      ($default_value ? $default_value['bundle'] : $first_bundle);

  if(isset($form_state['triggering_element']['#name']) &&
     $form_state['triggering_element']['#name'] == 'bundle_select') {
    $form_state['storage']['bundle'] = $form_state['input']['bundle_select'];
  }
    
  $form['bundle'] = array(
    '#type' => 'select',
    '#title' => t('Bundle'),
    '#options' => $bundles,
    '#name' => 'bundle_select',
    '#default_value' => $default_value ? $default_value['bundle'] : '',
    '#ajax' => [
      'callback' => 'wishlist_ajax_bundle_select_callback',
      'wrapper' => 'image_field',
    ],
  );
  
  $field_info = field_info_instances('node', $form_state['storage']['bundle']);
  
  $fields = [];
  //dpm($field_info);
  foreach($field_info as $key => $val) {
    if($val['widget']['type'] === 'image_image')
      $fields[$key] = $val['label'];
  }
  
  $form['image_field'] = array(
    '#type' => 'select',
    '#title' => t('Image Field'),
    '#name' => 'image_field',
    '#default_value' => $default_value ? $default_value['image_field'] : '',
    '#options' => $fields,
    '#prefix' => '<div id="image_field">',
    '#suffix' => '</div>',
  );
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  
  return $form;
}

function wishlist_ajax_bundle_select_callback($form, &$form_state) {
  return $form['image_field'];
}


function wishlist_settings_form_submit($form, &$form_state) {
  $values = $form_state['input'];
  
  variable_set('wishlist_settings', [
    'bundle' => $values['bundle_select'],
    'image_field' => $values['image_field'],
  ]);
  
  drupal_set_message(t('Settings save succefully!!!!!'));
}