<?php

/**
 * @file
 * Drush commands for Domain Access.
 */

/**
 * Implements hook_drush_command().
 */
function domain_locale_drush_command() {
  $items = array();
  $items['domain-locale-set'] = array(
    'description' => 'Add specific language settings to a site.',
    'examples' => array(
      'drush domain-locale-set example.com \'de\'',
      'drush domain-locale-set example.com \'de fr\' --weight=-1 --default=fr',
    ),
    'arguments' => array(
      'domain' => 'The domain to register (e.g. example.com).',
      'languages' => 'The prefixes of the languages to enable for this site (e.g. \'en\', \'en de\', ...).',
    ),
    'options' => array(
      'default' => 'The prefix of the default language for this domain.',
    ),
  );
  return $items;
}

/**
 * Add a language to a site.
 *
 * @param $subdomain
 *   The domain name to register.
 * @param $lang_prefixes
 *   The prefixes of the languages to enable
 *
 * @return
 *   Nothing if ok, or an error message.
 */
function drush_domain_locale_domain_locale_set($subdomain, $lang_prefixes) {
  // validate subdomain, get domain_id
  $machine_name = domain_machine_name($subdomain);
  $domain = domain_machine_name_load($machine_name);
  if (! $domain) {
    return drush_set_error('domain_locale', sprintf("Domain %s not found.", $subdomain));
  }
  $domain_id = $domain['domain_id'];

  // get and validate languages for the domain
  $langs = explode(" ", $lang_prefixes);
  $available_languages = language_list();
  foreach ($langs as $lang) {
    if (! isset($available_languages[$lang])) {
      return drush_set_error('domain_locale', sprintf("Language %s not available.", $lang));
    }
  }

  // get and validate default language
  $default = (drush_get_option('default')) ? drush_get_option('default') : null;
  if ($default && !in_array($default, $langs)) {
    return drush_set_error('domain_locale', sprintf("Default language '%s' must be present in 'languages' parameter.", $default));
  }
  if (!$default && count($langs) == 1) {
    $default = $lang;
  }

  // update db
  $params = array();
  foreach ($langs as $lang) {
    $params[] = array('language' => $lang);
  }
  domain_locale_delete_domain($domain_id);
  domain_locale_insert_domain($domain_id, $params);

  if ($default) {
    domain_conf_variable_set($domain_id, 'language_default', $default);
  }

  // clear cache
  cache_clear_all('*', 'cache_page', TRUE);

  drush_log(sprintf("Locale settings updated for %s", $subdomain), 'ok');
}
