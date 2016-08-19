<?php
/**
* @file
* Administration page callbacks for the annotate module.
*/
/**
* Form builder. Configure annotations.
*
* @ingroup forms
* @see system_settings_form().
*/
function product_manager_admin_settings() {
  // Get an array of node types with internal names as keys and
  // "friendly names" as values. E.g.,
  // array('page' => ’Basic Page, 'article' => 'Articles')
  
  $form['product_manager_band'] = array(
    '#type' => 'radios',
    '#title' => t('Select Band'),
    '#description' => t('Select a band for this website.'),
    '#options' => array(
      t('English'),
      t('Romanian'),
      t('Hungaryan'),
      t('France'),
      ),

    );
  
  
  
  //$form['#submit'][] = 'product_manager_admin_settings_submit';
  return $form;
}

/**
* Process annotation settings submission.
*/
function product_manager_admin_settings_submit($form, $form_state) {
  // Loop through each of the content type checkboxes shown on the form.
 
}

/**
* Validate annotation settings submission.
*/
function product_manager_admin_settings_validate($form, &$form_state) {
  $limit = $form_state['values']['product_manager_limit_per_node'];
  if (!is_numeric($limit)) {
    form_set_error('product_manager_limit_per_node', t('Please enter number.'));
  }
}
