<?php
//
//$wishlist = db_select('wishlist', 'w')
//            ->fields('w')
//            ->condition('uid', $_POSYT['user_id'])
//            ->execute()
//            ->fetchAll();
//print_r( $wishlist);       
//  $rows = prepar_rows($wishlist);
//  
//  $header = array('Product name', 'Created', 'Price','Description');
//  
//  $per_page = 5;
//  $current_page = pager_default_initialize(count($rows), $per_page);
//  $chunks = array_chunk($rows, $per_page, TRUE);
//
//  $output = theme('table', array('header' => $header, 'rows' => $chunks[$current_page]));
//
//  $output .= theme('pager', array('quantity',count($rows)));
//
//  print_r( $output); 
//  
//
//
//function prepar_rows($items) {
//  $rows = [];
//  
//  $key = 0;
//  foreach($items as $item) {
//    
//    $product = node_load($item->pid);
//   
//    $rows[$key]['name'] = $product->title;
//    $time = new DateTime();
//    $time->setTimestamp($product->created);
//    $rows[$key]['created'] = $time->format('d-m-Y');
//    $rows[$key]['price'] = $product->field_price['und'][0]['value'];
//    $rows[$key]['description'] = $product->field_description['und'][0]['value'];
//    $key++;
//  }
//  
//  return $rows;
//}
