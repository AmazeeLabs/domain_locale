<?php

/**
 * @file
 * Prints all the available languages per domains.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('All languages'),
  'description' => t('All the languages, per domain.'),

  // 'single' => TRUE means has no subtypes.
  'single' => TRUE,
  // Constructor.
  'content_types' => array('domain_locale_all_langauges'),
  // Name of a function which will render the block.
  'render callback' => 'domain_locale_all_languages_render',
  // The default context.
  'defaults' => array(),
  'category' => array(t('Custom'), -9),
);

/**
 * Run-time rendering of the body of the block.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context
 *
 * @return
 *   An object with at least title and content members.
 */
function domain_locale_all_languages_render($subtype, $conf, $args, $context) {
  $node = isset($context->data) ? $context->data : NULL;

  $block = new stdClass();
  // The title actually used in rendering
  $block->title = "";
  $variables = array();
  $domains = domain_domains();
  $all_languages = language_list('enabled');
  foreach ($domains as $domain) {
    // Small hack: if we have a variant, then use its path instead (if the first
    // variant in the list).
    $path = $domain['path'];
    if (!empty($domain['variants'])) {
      $variant = reset($domain['variants']);
      $path = $domain['scheme'] . '://' . $variant->path . '/';
    }
    $variables['domains'][$domain['machine_name']] = array(
      'name' => $domain['sitename'],
      'path' => $path,
      'machine_name' => $domain['machine_name'],
    );
    $languages = domain_locale_lookup($domain['domain_id']);
    foreach ($languages as $langcode => $lang) {
      if (!empty($all_languages[1][$langcode])) {
        $variables['domains'][$domain['machine_name']]['languages'][$langcode] = $all_languages[1][$langcode];
      }
    }
  }
  $block->content = theme('domain_locale_all_languages', $variables);
  return $block;
}
