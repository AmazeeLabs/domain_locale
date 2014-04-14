<?php

/**
 * @file
 *  Default page for "All languages".
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function domain_locale_default_page_manager_pages() {
  $pages = array();
  $path = drupal_get_path('module', 'domain_locale') . '/pages/domain_locale_all_languages.inc';
  include_once $path;
  // After inluding the file, the $page object should be available.
  $pages[$page->name] = $page;
  return $pages;
}
