<?php


function wishlist_list() {
  global $user;
  $path = drupal_get_path('module', 'wishlist');
  
  //drupal_add_css($path . '/css/top_wishlist.css');
  
  global $user;
  
  $wishlist = db_select('wishlist', 'w')
            ->fields('w')
            ->condition('uid', $user->uid)
            ->execute()
            ->fetchAll();
  
  $rows = whislist_prepar_rows($wishlist);
  
  $header = array('Product name', 'Created', 'Price', 'Image', 'Description', '');
  
  $per_page = 5;
  $current_page = pager_default_initialize(count($rows), $per_page);
  if(!empty($rows)){
    $chunks = array_chunk($rows, $per_page, TRUE);
  
    $output = theme('table', array('header' => $header, 'rows' => $chunks[$current_page]));
  
    $output .= theme('pager', array('quantity',count($rows)));
  }
  else {
    $output = "<h2>No Item in wishlist!!!</h2>";
  }
  return $output; 
}


function whislist_prepar_rows($items) {
  $rows = [];

  $key = 0;
  foreach($items as $item) {
    
    $product = node_load($item->pid);
   
    $rows[$key]['name'] = l($product->title, 'node/'. $product->vid);
    $time = new DateTime();
    $time->setTimestamp($product->created);
    $rows[$key]['created'] = $time->format('d-m-Y');
    $rows[$key]['price'] = '$ '. $product->field_price['und'][0]['value'];
    $rows[$key]['images'] = theme('image_style',array('style_name' => 'thumbnail', 'path' => $product->field_images['und'][0]['uri']));
    $rows[$key]['description'] = $product->field_description['und'][0]['value'];
    $rows[$key]['delete'] = l('Delete', 'delete/'. $item->id, array('attributes' => array('class' => array('btn btn-danger'))));
    $key++;
  
  }
  
  return $rows;
}
